#ifndef MY_BUZZ_H
#define MY_BUTTON_H

#include <Arduino.h>

class Buzz {
  
    private:
       byte pin;
       unsigned int frequency;
       unsigned long duration;
  
    public:
       Buzz(byte pin);
       void gameOverBuzz1(byte pin);
       void gameOverBuzz2(byte pin);
};

#endif
