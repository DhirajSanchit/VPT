#include "Buzz.h"
#include "SerialCommLed.h"
#include <LiquidCrystal.h>
#include <EEPROM.h>

#define LED_PIN 15
#define BUZZER_PIN 19

Buzz piezo (BUZZER_PIN);
SerialCommLed ledje (LED_PIN);


// Arduino pins connected to the 1602A LCD
const int rs = 10, en = 11, d4 = 12, d5 = 13, d6 = 18, d7 = 17; // I/O pins 18 & 17 = pins A4 & A3
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Arduino pin connected to the speaker
const int tonePin = 19; // I/O pin 19 = pin A5

// Arduino pins connected to leds
const int leds[] = { 9, 8, 7, 6 };

// Arduino pins connected to buttons
const int buttons[] = { 5, 4 , 3, 2 };

// Frequencies of tones played when buttons are pressed
const int toneFreq[] = { 277, 311, 370, 415 }; // CS4, DS4, FS4, GS4

// Enums for gamestate
enum {
  STATE_START_MENU,
  STATE_GAME,
  STATE_GAME_OVER
};

int score = 0;
int led = 0;
int prevLed = 0;
int nextTimer = 0;
int level = 0;
int hiscore = 0;
int startMenuTimer = 0;
int prevButtonState[] = { HIGH, HIGH, HIGH, HIGH };
int state = STATE_START_MENU;
String serialCommand = "";
bool commStarted = false;

const char startKarakter = '#';
const char eindKarakter = '%';


// Read hiscore value from EEPROM (1024 byte on-board data storage and can store integers from 0-255 per address(2 pow 8 = 256))
void readHiscore() {
  hiscore = (EEPROM.read(0) << 8) + EEPROM.read(1);
  
  // EEPROM initial value is FFFF (= 65535 = 256 pow 256)
  if(hiscore == 0xffff)
    hiscore = 0;
}

// Write hiscore value to EEPROM (1024 byte on-board data storage)
void writeHiscore() {
  EEPROM.write(0, hiscore >> 8); // = hiscore 
  EEPROM.write(1, hiscore & 0xff);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Game 'React-On-Time' launching...");
  lcd.begin(16, 2);
  lcd.print("YEEEEET?");
  delay(1000);
  lcd.clear();

  for(int i = 0; i < 4; i++){
    pinMode(leds[i], OUTPUT);
  }

  // enable pull up resistors for button pins
  for(int i = 0; i < 4; i++){
    pinMode(buttons[i], INPUT_PULLUP);
  }

  // checkt of er al een hiscore opgeslagen staat 
  readHiscore();
}

// Main loop. Update menu, game or game over depending on current state.
void loop() {
  if(state == STATE_START_MENU)
    startMenu();
  else if(state == STATE_GAME)
    playGame();
  else
    gameOver();
}

// Updates display with current score.
// Flashes 4 digits quickly on the display.
// Display is turned off if enable is false.
void updateDisplay(int _score, boolean screen) {    
  int S = _score;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Huidige score:");
  lcd.setCursor(4, 1);
  lcd.print(S);

  // Scherm gaat uit
  if(screen == false){
    lcd.noDisplay();
    delayMicroseconds(2000);
  }
  else if(screen == true){
    lcd.display();
  }
}

// Updates the start menu. Switch between previous score and hiscore on the display.
// Start a new game when a button is pressed. Clear the hiscore if all buttons are held down for 2 seconds.
void startMenu() {
  int S = score;

  // flick between previous score and hiscore display
  startMenuTimer = (startMenuTimer + 1) % 2000;
  if(startMenuTimer >= 1000){
    S = hiscore;
  }

  welcomeStart();
  updateDisplay(S, true);
  
  // read button state
  int buttonState = 0;
  for(int i = 0; i < 4; i++){
    if(digitalRead(buttons[i]) == LOW){
      buttonState += 1<<i; // buttonState = 1 -> 3 -> 7 -> 15
    }
  }
  // reset hiscore if all buttons are held down for 2 seconds
  static long resetHiscoreTimer = 0;
  if(buttonState == 15) {
    if(resetHiscoreTimer == 0){
      resetHiscoreTimer = millis();
    }
    if(millis() - resetHiscoreTimer > 2000) {
      updateDisplay(0, true);
      tone(tonePin, 500, 500);
      hiscore = 0;
      writeHiscore();
      delay(700);
      resetHiscoreTimer = 0;
    }
  } else {
    resetHiscoreTimer = 0;
  }
  
  // start new game if a single button is pressed for 100ms
  static int startNewGameTimer = 0;
  if(buttonState == 1 || buttonState == 2 || buttonState == 4 || buttonState == 8){
    if(startNewGameTimer == 0){
      startNewGameTimer = millis();
    }
    if(millis() - startNewGameTimer > 100) {  
      // start new game
      updateDisplay(score, false);
      delay(2000);
      startNewGame();
      startNewGameTimer = 0;
    }
  } else {
    startNewGameTimer = 0;
  }
}

// Prepares game state for a new game.
void startNewGame() {
  state = STATE_GAME;
  score = 0;
  level = -1;
  led = -1;
  prevLed = -1;
  nextTimer = 0;
 
  for(int i = 0; i < 4; i++){
    prevButtonState[i] = HIGH;
  }
  // set random seed, so that every game has a different sequence
  randomSeed(millis());
}

void playGame() {
  // update time
  nextTimer--;
  
  if(nextTimer < 0) {
    // game over if player is too slow
    if(led >= 0) {
      gameOver();
      return;
    }

    led = random(4);
    
    // make consequent same leds less probable
    if(led == prevLed && random(10) < 6){
      led = random(4);
    }
    prevLed = led;
    
    nextTimer = max(150 * pow(1.6, -level*0.05), 10);
    level++;
    
    tone(tonePin, toneFreq[led], nextTimer * 8);
    
    score = level;
  }
  
  // update leds
  for(int i = 0; i < 4; i++){
    int ledState = digitalRead(leds[i]);
    digitalWrite(leds[i], led == i || (digitalRead(buttons[i]) == LOW && nextTimer > 5) ? HIGH : LOW);
    Serial.println(ledState); // led turns on if a button is pressed and nextTimer is 
  }
   
  updateDisplay(score, true);
  
  // read input   
  for(int i = 0; i < 4; i++) {
    int buttonInput = digitalRead(buttons[i]);
    if(buttonInput == LOW && prevButtonState[i] == HIGH){
      // ignore button press if time since last press is too short
      if( led >= 0 ) { //&& millis() - lastButtonPress > 50 ) { 
        // correct button pressed?
        Serial.println(buttonInput);
        if( i == led ) {
          score++;
          led = -1;  // turn off led
        } else {
          gameOver();
          serialComms();
        }
        //lastButtonPress = millis();
        noTone(tonePin);
      }
    }
    prevButtonState[i] = buttonInput;
  }
}

// Game over. Play a game over sound and blink score.
void gameOver() {
  piezo.gameOverBuzz1(BUZZER_PIN);
  Serial.println("Game has ended.");

  // new hiscore?
  if(score > hiscore) {
    hiscore = score;
    writeHiscore();
    Serial.println("Congratulations! A new hiscore has been set!");
    Serial.println("New hiscore: " + hiscore);
    Serial.println("Play again?");
  }
  
  else if (score <= hiscore){
    Serial.println("Your score: " + score);
    Serial.println("Play again?");
  }
  
  // turn on -> off -> on leds
  for(int i = 0; i < 4; i++){
    digitalWrite(leds[i], HIGH);
  }
  delay(1000);
  for(int i = 0; i < 4; i++){
    digitalWrite(leds[i], LOW);
  }
  delay(1000);
  for(int i = 3; i > -1; i--){
    digitalWrite(leds[i], HIGH);
  }
  delay(1000);

  piezo.gameOverBuzz2(BUZZER_PIN);
  
  // turn off leds
  for(int i = 0; i < 4; i++){
    digitalWrite(leds[i], LOW);
  }
  delay(500);

  gameOverScreen();
  
  // enter menu
  delay(1000);
  state = STATE_START_MENU;
  startMenuTimer = 0;
}

void welcomeStart(){
  int H = hiscore;

  if(H == 0){
    firstTimeStart();
  }

  else if(H > 0){
    normalStart(H);
  }
}

void firstTimeStart(){
  lcd.display();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Welkom Ertugrul!");
  lcd.setCursor(4, 1);
  lcd.print("Let's go?");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0, 0);
  Serial.println("Shortly press a button to get started!");
  lcd.print("Druk op een knop");
  lcd.setCursor(1, 1);
  lcd.print("om te beginnen!");
}

void normalStart(int _hiscore){
  lcd.display();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Welkom Ertugrul!");
  lcd.setCursor(4, 1);
  lcd.print("Let's go?");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Huidige hiscore:");
  lcd.setCursor(4, 1);
  lcd.print(hiscore);
  delay(1500);
  lcd.clear();
  Serial.println("Shortly press a button to get started!");
  lcd.print("Druk op een knop");
  lcd.setCursor(1, 1);
  lcd.print("om te beginnen!");
  delay(2000);
}

void gameOverScreen(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Game Over!");
  lcd.setCursor(4, 1);
  lcd.print("Score:" + score);
  delay(2000);
  lcd.setCursor(0, 0);
  lcd.print("Play again?");
  delay(3000);

  // insert: restart game with buttonpress code
}

void serialComms(){
    char readByte = Serial.read();
    if (readByte == startKarakter){
        serialCommand = "";
        commStarted = true;
    }
    else if(commStarted){
        if(readByte == eindKarakter){
            commStarted = false;
            handleMessage(serialCommand);
        }
        else{
            serialCommand += readByte;
        }
    }
}

void handleMessage(String message){
    if (message.equals("SET_LED_ON")){
        ledje.turnOn();
    }
    else if (message.equals("SET_LED_OFF")){
        ledje.turnOff();
    }
    else if (message.startsWith("DIM_LED:")){
        int index = message.indexOf(':');
        String getal = message.substring(index + 1);
        getal.trim();
        int value = getal.toInt();
        analogWrite(LED_PIN, value);
    }
}
