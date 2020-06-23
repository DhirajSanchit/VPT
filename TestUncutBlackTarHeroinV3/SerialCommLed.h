#ifndef MY_SERIALCOMMLED_H
#define MY_SERIALCOMMLED_H

#include <Arduino.h>

class SerialCommLed {

    private:
      byte pin;

    public:
      SerialCommLed(byte pin);
    
      void init();
      void turnOn();
      void turnOff();
};

#endif
