#include "Buzz.h"

    Buzz::Buzz(byte pin){
      this->pin = pin;
      frequency = 0;
      duration = 0;
    }

    void Buzz::gameOverBuzz1(byte pin){
        tone(pin, 250, 2500);
    }

    void Buzz::gameOverBuzz2(byte pin){
        tone(pin, 200, 1000);
    }
