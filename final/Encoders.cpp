#include <Arduino.h>
#include "Encoders.h"

Encoders::Encoders() {
  left_aSet = false, right_aSet = false,
	left_bSet = false, right_bSet = false;
	
  attachInterrupt(
  digitalPinToInterrupt(
	LEFT_ENCODER_PIN_A),
	leftTriggerA,
	CHANGE);
  attachInterrupt(
	digitalPinToInterrupt(
	LEFT_ENCODER_PIN_B),
	leftTriggerB,
	RISING);
  attachInterrupt(
	digitalPinToInterrupt(LEFT_ENCODER_PIN_A),
	rightTriggerA,
	CHANGE);
  attachInterrupt(
	digitalPinToInterrupt(LEFT_ENCODER_PIN_B),
	rightTriggerB,
	RISING);

}

void Encoders::leftTriggerA() {
  triggerA(left_aSet, left_bSet, left_ENCODER_PIN_A, left_periodStart, left_sum, left_rate);
}

void Encoders::leftTriggerB() {
  triggerB(left_bSet);
}

void Encoders::rightTriggerA() {
  triggerA(right_aSet, right_bSet, RIGHT_ENCODER_PIN_A, right_periodStart, right_sum, right_rate);
}

void Encoders::rightTriggerB() {
  triggerB(right_bSet);
}

inline void triggerA(bool aSet, bool bSet, int pinA, long periodStart, long sum, long rate){
  bSet = false;
  if(digitalRead(pinA)){
    aSet  = true;
    periodStart = micros();
  }else if(aSet){
    aSet = false;
    if(bSet){
      rate = 1/(micros() - periodStart);
      ++sum;
    }else{
      rate = -1/(micros() - periodStart);
      --sum;
    }
    
  }else{
    if(bSet){
      ++sum;
    }else{
      --sum;
    }
  }
}

inline void triggerB(bool bset){
  bSet = true;
}
