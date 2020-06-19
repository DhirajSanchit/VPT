#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "klassen.ino"

//Connecting to wifi
#include <NTPClient.h>
#include <WiFi.h>;
#include <WiFiUdp.h>

const char* ssid = "It hurts when IP";      //Name of the wWiFi
const char* password = "milkandhoney";      //WiFi password

const long utcOffsetInSeconds = 7200;

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

LiquidCrystal_I2C lcd(0x3F, 16, 2);


#define CHOICE_OFF      0 //Used to control LEDs
#define CHOICE_NONE     0 //Used to check buttons
#define CHOICE_BLUE    (1 << 0)
#define CHOICE_RED     (1 << 1)
#define CHOICE_YELLOW  (1 << 2)
#define CHOICE_GREEN   (1 << 3)

int LED_GREEN =     32;
int LED_YELLOW =    25;
int LED_RED =       27;
int LED_BLUE =      13;

//define button pin games
#define BUTTON_PINK_MEMORY  19
#define BUTTON_BLUE_HIT     18
int buttonStatePink = 0;
int buttonStateBlue = 0;


// Button pin definitions
int BUTTON_GREEN =    33;
int BUTTON_YELLOW =   26;
int BUTTON_RED =      14;
int BUTTON_BLUE =     12;

int gameMode = 0;


// Buzzer pin definitions
const int buzzer1 = 5;
const int buzzer2 = 17;

// Define game parameters
#define ROUNDS_TO_WIN      13 //Number of rounds to succesfully remember before you win. 13 is do-able.
#define ENTRY_TIME_LIMIT   3000 //Amount of time to press a button before game times out. 3000ms = 3 sec



// Game state variables

byte gameBoard[32]; //Contains the combination of buttons as we advance
byte gameRound = 0; //Counts the number of succesful rounds the player has made it through

  Led ledR (LED_RED);
  Led ledG (LED_GREEN);
  Led ledB (LED_BLUE);
  Led ledY (LED_YELLOW);

  Buz b(buzzer1, buzzer2);


void setup()
{
  //Setup hardware inputs/outputs. These pins are defined in the hardware_versions header file

  //Enable pull ups on inputs
  pinMode(BUTTON_RED, INPUT_PULLUP);
  pinMode(BUTTON_GREEN, INPUT_PULLUP);
  pinMode(BUTTON_BLUE, INPUT_PULLUP);
  pinMode(BUTTON_YELLOW, INPUT_PULLUP);
  pinMode(BUTTON_PINK_MEMORY, INPUT_PULLUP);
  pinMode(BUTTON_BLUE_HIT, INPUT_PULLUP);

  lcd.init();                   // initializes LCD screen
  lcd.backlight();              // turns on blacklight
  

  b.win(); 
  b.win();      // After setup is complete, say hello to the world



//WiFi settings

  Serial.begin(115200);
  WiFi.begin(ssid, password);


  while (WiFi.status() != WL_CONNECTED){
  Serial.println(".");
  delay(500);
}
}

void loop(){

//welcome screen
  timeClient.update();


  if (timeClient.getHours() < 12.00){
  lcd.clear();                             // erase screen
  lcd.setCursor(0, 0);                     // put cursor on position 1, line 1
  lcd.print("Goeden morgen");              // write on screen
  lcd.setCursor(0, 1);                     // put cursor on position 1, line 2
  lcd.print("Melvin");                    // write on screen
  delay(1000);                             // pause for 1 second
  }

 if (timeClient.getHours() > 12.00 && timeClient.getHours() < 17.00) {
    lcd.clear();                             // erase screen
    lcd.setCursor(0, 0);                     // put cursor on position 1, line 1
    lcd.print("Goeden middag");              // write on screen
    lcd.setCursor(0, 1);                     // put cursor on position 1, line 2
    lcd.print("Melvin");                    // write on screen
    delay(1000);                             // pause for 1 second
  }

 if (timeClient.getHours() > 17.00) {
  lcd.clear();                             // erase screen
  lcd.setCursor(0, 0);                     // put cursor on position 1, line 1
  lcd.print("Goeden avond");               // write on screen
  lcd.setCursor(0, 1);                     // put cursor on position 1, line 2
  lcd.print("Melvin");                    // write on screen
  delay(1000);                             // pause for 1 second
 }
  
//choose a game screen

  lcd.clear();                  // erase scherm
  lcd.setCursor(0, 0);                     // put cursor on position 1, line 1
  lcd.print("Kies een spel");             // write on screen
  lcd.setCursor(0, 1);
  lcd.print("om te beginnen.");
  delay(1000);                 // pause for 1 seconde

buttonStatePink = digitalRead(BUTTON_PINK_MEMORY);
buttonStateBlue = digitalRead(BUTTON_BLUE_HIT);


    if (buttonStateBlue == LOW)
  {
        ledB.on();
        ledR.on();
        ledY.on();
        ledG.on();

         gameMode++;
        
        lcd.clear();                        // erase screen
        lcd.setCursor(0, 0);                // put cursor on position 1, line 1
        lcd.print("Gekozen spel: ");       // write on screen
        lcd.setCursor(0, 1);                // put cursor on position 1, line 2
        lcd.print("Hit-The-Light");               // write on screen
        delay(2000);

        lcd.clear();                        // erase screen
        lcd.setCursor(0, 0);                // put cursor on position 1, line 1
        lcd.print("Druk op een knop");       // write on screen
        lcd.setCursor(0, 1);                // put cursor on position 1, line 2
        lcd.print("Om te beginnen");               // write on screen
        delay(2000);

   attractMode(); // Blink lights while waiting for user to press a button
   
  setLEDs(CHOICE_RED | CHOICE_GREEN | CHOICE_BLUE | CHOICE_YELLOW); // Turn all LEDs on
  delay(1000);
  setLEDs(CHOICE_OFF); // Turn off LEDs
  delay(250);
  }
  
  if (buttonStatePink == LOW)
  {
        ledB.on();
        ledR.on();
        ledY.on();
        ledG.on();
           
    gameMode++;
    gameMode++;
        
        lcd.clear();                        // erase screen
        lcd.setCursor(0, 0);                // put cursor on position 1, line 1
        lcd.print("Gekozen spel: ");       // write on screen
        lcd.setCursor(0, 1);                // put cursor on position 1, line 2
        lcd.print("MeMoMove");               // write on screen
        delay(2000);
        
        lcd.clear();                        // erase screen
        lcd.setCursor(0, 0);                // put cursor on position 1, line 1
        lcd.print("Druk op een knop");       // write on screen
        lcd.setCursor(0, 1);                // put cursor on position 1, line 2
        lcd.print("Om te beginnen");               // write on screen
        delay(2000);


 attractMode(); // Blink lights while waiting for user to press a button

  // Indicate the start of game play
  setLEDs(CHOICE_RED | CHOICE_GREEN | CHOICE_BLUE | CHOICE_YELLOW); // Turn all LEDs on
  delay(1000);
  setLEDs(CHOICE_OFF); // Turn off LEDs
  delay(250);
    
  }

    if (gameMode == 1)      //game needs to be uploaded, this is just an example
  {
        
        ledB.off();
        ledR.on();
        ledY.off();
        ledG.on();
        
    delay(1000);

    gameMode--;
  }

 if (gameMode == 2){
        
    // Play memory game and handle result
    if (play_memory() == true) 
      play_winner(); // Player won, play winner tones
    else 
      play_loser(); // Player lost, play loser tones
      gameMode--;
      gameMode--;
  } 

   if (gameMode == 0)
  {
    ledR.on();
    ledB.on();
    ledY.on();
    ledG.on();

    lcd.clear();
    screenKnopZijkant();
    delay(2000);
  } 
}



void screenHelaas() {
  lcd.setCursor(0, 0);                        // put cursor on position 1, line 1
  lcd.print("Helaas!");                       // write on screen

}

void screenBehaaldeRondes() {               
  lcd.setCursor(0, 0);                        // put cursor on position 1, line 1
  lcd.print("Behaalde rondes:");              // write on screen
  lcd.setCursor(7, 1);                        // put cursor on position 6, line 2
  lcd.print(gameRound - 1);                   // write on screen
}

void screenKnopZijkant(){
  lcd.setCursor(0, 0);
  lcd.print("Druk op een knop");
  lcd.setCursor(0, 1);
  lcd.print("aan de zijkant.");
}




//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//The following functions are related to game play only

// Play the regular memory game
// Returns 0 if player loses, or 1 if player wins
boolean play_memory(void)
{
  
  randomSeed(millis()); // Seed the random generator with random amount of millis()

  gameRound = 0; // Reset the game to the beginning

  while (gameRound < ROUNDS_TO_WIN) 
  {
    add_to_moves(); // Add a button to the current moves, then play them back

    playMoves(); // Play back the current game board

    // Then require the player to repeat the sequence.
    for (byte currentMove = 0 ; currentMove < gameRound ; currentMove++)
    {
      byte choice = wait_for_button(); // See what button the user presses

      if (choice == 0){
        return false; // If wait timed out, player loses
      }

      if (choice != gameBoard[currentMove]) return false; // If the choice is incorect, player loses
     
    }

    delay(1000); // Player was correct, delay before playing moves
  }

  return true; // Player made it through all the rounds to win!
}


// Plays the current contents of the game moves
void playMoves()
{
  for (byte currentMove = 0 ; currentMove < gameRound ; currentMove++) 
  {
    toner(gameBoard[currentMove], 150);

    // Wait some amount of time between button playback
    // Shorten this to make game harder
    delay(150); // 150 works well. 75 gets fast.
    
  }
}

// Adds a new random button to the game sequence, by sampling the timer
void add_to_moves()
{
  byte newButton = random(0, 4); //min (included), max (exluded)

  // We have to convert this number, 0 to 3, to CHOICEs
  if(newButton == 0) newButton = CHOICE_RED;
  else if(newButton == 1) newButton = CHOICE_GREEN;
  else if(newButton == 2) newButton = CHOICE_BLUE;
  else if(newButton == 3) newButton = CHOICE_YELLOW;

  gameBoard[gameRound++] = newButton; // Add this new button to the game array

        lcd.clear();                        // erase screen
        lcd.setCursor(0, 0);                // put cursor on position 1, line 1
        lcd.print("Huidige ronde: ");       // write on screen
        lcd.setCursor(7, 1);                // put cursor on position 1, line 2
        lcd.print(gameRound);               // write on screen
}

//The following functions control the hardware

// Lights a given LEDs
// Pass in a byte that is made up from CHOICE_RED, CHOICE_YELLOW, etc
void setLEDs(byte leds)
{
  if ((leds & CHOICE_RED) != 0)
    ledR.on();
  else
    ledR.off();

  if ((leds & CHOICE_GREEN) != 0)
   ledG.on();
  else
   ledG.off();
   
  if ((leds & CHOICE_BLUE) != 0)
    ledB.on();
  else
    ledB.off();

  if ((leds & CHOICE_YELLOW) != 0)
    ledY.on();
  else
    ledY.off();
}

// Wait for a button to be pressed. 
// Returns one of LED colors (LED_RED, etc.) if successful, 0 if timed out
byte wait_for_button(void)
{
  long startTime = millis(); // Remember the time we started the this loop

  while ( (millis() - startTime) < ENTRY_TIME_LIMIT) // Loop until too much time has passed
  {
    byte button = checkButton();

    if (button != CHOICE_NONE)
    { 
      toner(button, 150); // Play the button the user just pressed

      while(checkButton() != CHOICE_NONE) ;  // Now let's wait for user to release button

      delay(10); // This helps with debouncing and accidental double taps

      return button;
    }

  }

  return CHOICE_NONE; // If we get here, we've timed out!
}

// Returns a '1' bit in the position corresponding to CHOICE_RED, CHOICE_GREEN, etc.
byte checkButton()
{
  if (digitalRead(BUTTON_RED) == 0) return(CHOICE_RED); 
  else if (digitalRead(BUTTON_GREEN) == 0) return(CHOICE_GREEN); 
  else if (digitalRead(BUTTON_BLUE) == 0) return(CHOICE_BLUE); 
  else if (digitalRead(BUTTON_YELLOW) == 0) return(CHOICE_YELLOW);

  return(CHOICE_NONE); // If no button is pressed, return none
}

// Light an LED and play tone
// Red, upper left:     440Hz - 2.272ms - 1.136ms pulse
// Green, upper right:  880Hz - 1.136ms - 0.568ms pulse
// Blue, lower left:    587.33Hz - 1.702ms - 0.851ms pulse
// Yellow, lower right: 784Hz - 1.276ms - 0.638ms pulse
void toner(byte which, int buzz_length_ms)
{
  setLEDs(which); //Turn on a given LED

  //Play the sound associated with the given LED
  switch(which) 
  {
  case CHOICE_BLUE:
    b.blueSound();
    break;
  case CHOICE_RED:
    b.redSound();
    break;
  case CHOICE_YELLOW:
   b.yellowSound();
   break;
  case CHOICE_GREEN:
   b.greenSound();
   break;
  }

  setLEDs(CHOICE_OFF); // Turn off all LEDs
}


// Play the winner sound and lights
void play_winner()
{
  setLEDs(CHOICE_GREEN | CHOICE_BLUE);
  b.win();
  setLEDs(CHOICE_RED | CHOICE_YELLOW);
  b.win();
  setLEDs(CHOICE_GREEN | CHOICE_BLUE);
  b.win();
  setLEDs(CHOICE_RED | CHOICE_YELLOW);
  b.win();
}

// Play the loser sound/lights
void play_loser()
{
  

  setLEDs(CHOICE_RED | CHOICE_GREEN);
  b.lose();

  setLEDs(CHOICE_BLUE | CHOICE_YELLOW);
  b.lose();

  setLEDs(CHOICE_RED | CHOICE_GREEN);
  b.lose();

  setLEDs(CHOICE_BLUE | CHOICE_YELLOW);
  b.lose();
  
  lcd.clear();                 // erase screen
  setLEDs(CHOICE_RED | CHOICE_GREEN);
  screenHelaas();                   // perform function screen 3
  setLEDs(CHOICE_BLUE | CHOICE_YELLOW);
  delay(1000);                 // pause for 1 second
  lcd.clear();                 // erase screen
  setLEDs(CHOICE_RED | CHOICE_GREEN);
  screenBehaaldeRondes(); // perform function screen 4
  setLEDs(CHOICE_BLUE | CHOICE_YELLOW);
  delay(2000);                 // pause for 1 second

  Serial.println("Behaalde score: ");
  Serial.println(gameRound - 1);
  Serial.println("------------------------------------------------");


}


// Show an "attract mode" display while waiting for user to press button.
void attractMode()
{
  while(1) 
  {
    ledB.on();
    delay(100);
    ledB.off();
    if (checkButton() != CHOICE_NONE) return;

    ledR.on();
    delay(100);
    ledR.off();
    if (checkButton() != CHOICE_NONE) return;

    ledY.on();
    delay(100);
    ledY.off();
    if (checkButton() != CHOICE_NONE) return;

    ledG.on();
    delay(100);
    ledG.off();
    if (checkButton() != CHOICE_NONE) return;

  }
}
