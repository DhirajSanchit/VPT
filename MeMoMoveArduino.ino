
// Bibliotheek voor communicatie met I2C / TWI apparaten
#include <Wire.h> 

// Bibliotheek voor het LCD scherm
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

#define CHOICE_OFF      0 //Used to control LEDs
#define CHOICE_NONE     0 //Used to check buttons
#define CHOICE_BLUE (1 << 0)
#define CHOICE_RED  (1 << 1)
#define CHOICE_YELLOW (1 << 2)
#define CHOICE_GREEN  (1 << 3)

#define LED_GREEN   7
#define LED_YELLOW  9
#define LED_RED     11
#define LED_BLUE    13

//define button pin games
#define BUTTON_PINK_MEMORY  4
#define BUTTON_BLUE_HIT     1
#define BUTTONSTATE         LOW      //variable for reading button state


// Button pin definitions
#define BUTTON_GREEN  6
#define BUTTON_YELLOW 8
#define BUTTON_RED    10
#define BUTTON_BLUE   12


// Buzzer pin definitions
#define BUZZER1  2
#define BUZZER2  3

// Define game parameters
#define ROUNDS_TO_WIN      13 //Number of rounds to succesfully remember before you win. 13 is do-able.
#define ENTRY_TIME_LIMIT   3000 //Amount of time to press a button before game times out. 3000ms = 3 sec

#define MODE_MEMORY  0

// Game state variables
byte gameMode = MODE_MEMORY; //By default, let's play the memory game
byte gameBoard[32]; //Contains the combination of buttons as we advance
byte gameRound = 0; //Counts the number of succesful rounds the player has made it through

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

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);

  pinMode(BUZZER1, OUTPUT);
  pinMode(BUZZER2, OUTPUT);


  lcd.init();                   // initializes LCD screen
  lcd.backlight();              // turns on blacklight
  

  play_winner(); // After setup is complete, say hello to the world
}

void loop()
{
  lcd.clear();                 // erase screen

  screen1();                   // perform function screen1
  delay(1000);                 // pause for 1 second

 lcd.clear();                  // erase scherm
  screen2();                   // perform function screen2
  delay(1000);                 // pause for 1 seconde

  attractMode(); // Blink lights while waiting for user to press a button

  // Indicate the start of game play
  setLEDs(CHOICE_RED | CHOICE_GREEN | CHOICE_BLUE | CHOICE_YELLOW); // Turn all LEDs on
  delay(1000);
  setLEDs(CHOICE_OFF); // Turn off LEDs
  delay(250);

  if (gameMode == MODE_MEMORY)
  {
    // Play memory game and handle result
    if (play_memory() == true) 
      play_winner(); // Player won, play winner tones
    else 
      play_loser(); // Player lost, play loser tones
  } 
}

void screen1() {
  lcd.setCursor(0, 0);                     // put cursor on position 1, line 1
  lcd.print("Welkom Heather!");            // write on screen

}

void screen2() {               
  lcd.setCursor(0, 0);                        // put cursor on position 1, line 1
  lcd.print("Druk op rood");                  // write on screen
  lcd.setCursor(0, 1);                        // put cursor on position 1, line 2
  lcd.print("om te beginnen.");               // write on screen
}

void screen3() {
  lcd.setCursor(0, 0);                        // put cursor on position 1, line 1
  lcd.print("Helaas!");                       // write on screen

}

void screen4() {               
  lcd.setCursor(0, 0);                        // put cursor on position 1, line 1
  lcd.print("Behaalde rondes:");              // write on screen
  lcd.setCursor(7, 1);                        // put cursor on position 1, line 2
  lcd.print(gameRound - 1);                   // write on screen
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
void playMoves(void)
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
void add_to_moves(void)
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
    digitalWrite(LED_RED, HIGH);
  else
    digitalWrite(LED_RED, LOW);

  if ((leds & CHOICE_GREEN) != 0)
    digitalWrite(LED_GREEN, HIGH);
  else
    digitalWrite(LED_GREEN, LOW);

  if ((leds & CHOICE_BLUE) != 0)
    digitalWrite(LED_BLUE, HIGH);
  else
    digitalWrite(LED_BLUE, LOW);

  if ((leds & CHOICE_YELLOW) != 0)
    digitalWrite(LED_YELLOW, HIGH);
  else
    digitalWrite(LED_YELLOW, LOW);
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
byte checkButton(void)
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
    buzz_sound(buzz_length_ms,  851); 
    break;
  case CHOICE_RED:
    buzz_sound(buzz_length_ms, 1136); 
    break;
  case CHOICE_YELLOW:
    buzz_sound(buzz_length_ms,  638); 
    break;
  case CHOICE_GREEN:
    buzz_sound(buzz_length_ms,  568); 
    break;
  }

  setLEDs(CHOICE_OFF); // Turn off all LEDs
}

// Toggle buzzer every buzz_delay_us, for a duration of buzz_length_ms.
void buzz_sound(int buzz_length_ms, int buzz_delay_us)
{
  // Convert total play time from milliseconds to microseconds
  long buzz_length_us = buzz_length_ms * (long)1000;

  // Loop until the remaining play time is less than a single buzz_delay_us
  while (buzz_length_us > (buzz_delay_us * 2))
  {
    buzz_length_us -= buzz_delay_us * 2; //Decrease the remaining play time

    // Toggle the buzzer at various speeds
    digitalWrite(BUZZER1, LOW);
    digitalWrite(BUZZER2, HIGH);
    delayMicroseconds(buzz_delay_us);

    digitalWrite(BUZZER1, HIGH);
    digitalWrite(BUZZER2, LOW);
    delayMicroseconds(buzz_delay_us);
  }
}

// Play the winner sound and lights
void play_winner(void)
{
  setLEDs(CHOICE_GREEN | CHOICE_BLUE);
  winner_sound();
  setLEDs(CHOICE_RED | CHOICE_YELLOW);
  winner_sound();
  setLEDs(CHOICE_GREEN | CHOICE_BLUE);
  winner_sound();
  setLEDs(CHOICE_RED | CHOICE_YELLOW);
  winner_sound();
}

// Play the winner sound
// This is just a unique (annoying) sound we came up with, there is no magic to it
void winner_sound(void)
{
  // Toggle the buzzer at various speeds
  for (byte x = 250 ; x > 70 ; x--)
  {
    for (byte y = 0 ; y < 3 ; y++)
    {
      digitalWrite(BUZZER2, HIGH);
      digitalWrite(BUZZER1, LOW);
      delayMicroseconds(x);

      digitalWrite(BUZZER2, LOW);
      digitalWrite(BUZZER1, HIGH);
      delayMicroseconds(x);
    }
  }
}

// Play the loser sound/lights
void play_loser(void)
{
        
  setLEDs(CHOICE_RED | CHOICE_GREEN);
  buzz_sound(255, 1500);

  setLEDs(CHOICE_BLUE | CHOICE_YELLOW);
  buzz_sound(255, 1500);

  setLEDs(CHOICE_RED | CHOICE_GREEN);
  buzz_sound(255, 1500);

  setLEDs(CHOICE_BLUE | CHOICE_YELLOW);
  buzz_sound(255, 1500);


  lcd.clear();                 // erase screen

  screen3();                   // perform function screen 3
  delay(1000);                 // pauze for 1 second
  
  lcd.clear();                 // erase screen

  screen4();                   // perform function screen 4
  delay(2000);                 // pauze for 1 second
}


// Show an "attract mode" display while waiting for user to press button.
void attractMode(void)
{
  while(1) 
  {
    setLEDs(CHOICE_BLUE);
    delay(100);
    if (checkButton() != CHOICE_NONE) return;

    setLEDs(CHOICE_RED);
    delay(100);
    if (checkButton() != CHOICE_NONE) return;

    setLEDs(CHOICE_YELLOW);
    delay(100);
    if (checkButton() != CHOICE_NONE) return;

    setLEDs(CHOICE_GREEN);
    delay(100);
    if (checkButton() != CHOICE_NONE) return;

  }
}