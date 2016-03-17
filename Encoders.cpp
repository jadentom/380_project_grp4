#include <Arduino.h>
#include "Encoders.h"

#define LEFT_ENCODER_PIN 18
#define RIGHT_ENCODER_PIN 2

Encoders::Encoders() {
   prev_left = 0;
   prev_right = 0;

   /*
   attachInterrupt(
    digitalPinToInterrupt(LEFT_ENCODER_PIN),
    leftTrigger,
    FALLING);
    
  attachInterrupt(
    digitalPinToInterrupt(LEFT_ENCODER_PIN),
    rightTrigger,
    FALLING); 
    */

}

void Encoders::leftTrigger() {

}

void Encoders::rightTrigger() {

}
