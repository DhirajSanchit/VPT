
class Led{

    private:
        int pin;

    public:
        Led(int pin){
            this->pin = pin;
            init();
        }
    
    void init(){
        pinMode(pin, OUTPUT);
        off();
    }

    void on(){
        digitalWrite(pin, HIGH);
    }
    void off(){
        digitalWrite(pin, LOW);
    }
};

class Buz{
  
    private:
      int buz1;
      int buz2;

    public:
      Buz(int buz1, int buz2){
          this->buz1 = buz1;
          this->buz2 = buz2;
          init();
      }
 
void init(){
  pinMode(buz1, OUTPUT);
  pinMode(buz2, OUTPUT);
}

void buzz_sound(int buzz_length_ms, int buzz_delay_us)
{
  // Convert total play time from milliseconds to microseconds
  long buzz_length_us = buzz_length_ms * (long)1000;

  // Loop until the remaining play time is less than a single buzz_delay_us
  while (buzz_length_us > (buzz_delay_us * 2))
  {
    buzz_length_us -= buzz_delay_us * 2; //Decrease the remaining play time

    // Toggle the buzzer at various speeds
    digitalWrite(buz1, LOW);
    digitalWrite(buz2, HIGH);
    delayMicroseconds(buzz_delay_us);

    digitalWrite(buz1, HIGH);
    digitalWrite(buz2, LOW);
    delayMicroseconds(buzz_delay_us);
  }
}

void win(){
   // Toggle the buzzer at various speeds
  for (byte x = 250 ; x > 70 ; x--)
  {
    for (byte y = 0 ; y < 3 ; y++)
    {
      digitalWrite(buz2, HIGH);
      digitalWrite(buz1, LOW);
      delayMicroseconds(x);

      digitalWrite(buz2, LOW);
      digitalWrite(buz1, HIGH);
      delayMicroseconds(x);
    }
  }
}

  void lose(){
    buzz_sound(255, 1500);
  }
  
  void blueSound(){
    buzz_sound(150,  851); 
  }

   void redSound(){
    buzz_sound(150,  1136); 
   }
  
   void yellowSound(){
     buzz_sound(150,   638); 
   }
    
  void greenSound(){
    buzz_sound(150,  568); 
  }
};


    
