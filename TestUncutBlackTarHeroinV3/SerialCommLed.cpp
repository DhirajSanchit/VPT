#include "SerialCommLed.h"

    SerialCommLed::SerialCommLed(byte pin){
          this->pin = pin;
          init();
      }
    
    void SerialCommLed::init(){
        pinMode(pin, OUTPUT);
        turnOff();
    }

    void SerialCommLed::turnOn(){
        digitalWrite(pin, HIGH);
    }

    void SerialCommLed::turnOff(){
        digitalWrite(pin, LOW);
    }
