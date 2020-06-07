#include <Arduino.h>

int sequence[15]={8,10,9,11,9,11,8,10,9,11,8,10,9,10,11};   //Array to set the blink sequence 
short int i, points; 
//unsigned long currentTime;

int LED_GREEN =      7;
int LED_YELLOW =     9;
int LED_RED =        11;
int LED_BLUE =       13;

// Button pin definitions
int BUTTON_GREEN =    6;
int BUTTON_YELLOW =   8;
int BUTTON_RED =     10;
int BUTTON_BLUE =    12;

int button1State = LOW;
int button2State = LOW;
int button3State = LOW;
int button4State = LOW;

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON_GREEN, INPUT_PULLUP);
  pinMode(BUTTON_YELLOW, INPUT_PULLUP);
  pinMode(BUTTON_RED, INPUT_PULLUP);
  pinMode(BUTTON_BLUE, INPUT_PULLUP);

  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(2), pointCount, RISING);
  randomSeed(analogRead(0));
  
  for (int i = 0; i < 30; i++)
  { 
   sequence[i] = randomArrayFill();
  }
}

void loop(){
  short int j;               
  for(j=0;j<=1;j++)                //2 rondes; elk 15 punten te scoren. Mss iets doen met difficulty round 1 en 2.
  {
    for(i=0;i<=14;i++)                       
    {
    digitalWrite(sequence[i],HIGH);
    delay(1500);
    digitalWrite(sequence[i],LOW);
    delay(100);
    }
  }
  Serial.println(points);          
  while(1);
}

void pointCount(){
 digitalWrite(sequence[i],LOW);
 points = points + 1;
}

int randomArrayFill(){
  int randomNumber = random(8,12);
  return randomNumber;
}