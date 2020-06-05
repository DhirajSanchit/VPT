int sequence[15]={8,10,9,11,9,11,8,10,9,11,8,10,9,10,11};   //Array to set the blink sequence 
short int i, points; 
//unsigned long currentTime;

int button1 = 1;
int button2 = 2;
int button3 = 3;
int button4 = 4;
int LED1 =  8;
int LED2 =  9;
int LED3 =  10;
int LED4 =  11;
int button1State = LOW;
int button2State = LOW;
int button3State = LOW;
int button4State = LOW;

void setup()
{
  Serial.begin(9600);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
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
