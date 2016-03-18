#include <Arduino.h>
#include "Encoders.h"

Encoders::Encoders() {
  left_aSet = false, right_aSet = false,
	  left_bSet = false, right_bSet = false;
  left_rate = 0, right_rate = 0;
  left_sum = 0, right_sum = 0,
    left_periodStart = 0, right_periodStart = 0;

}

inline void Encoders::leftTriggerA() {
  triggerA(left_aSet, left_bSet, LEFT_ENCODER_PIN_A, left_periodStart, left_sum, left_rate);
}

inline void Encoders::leftTriggerB() {
  triggerB(left_bSet);
}

inline void Encoders::rightTriggerA() {
  triggerA(right_aSet, right_bSet, RIGHT_ENCODER_PIN_A, right_periodStart, right_sum, right_rate);
}

inline void Encoders::rightTriggerB() {
  triggerB(right_bSet);
}

inline void Encoders::triggerA(bool& aSet, bool& bSet, int pinA, long& periodStart, long& sum, float& rate){
  bSet = false;
  if(digitalRead(pinA)){
    aSet  = true;
    periodStart = micros();
  }else if(aSet){
    aSet = false;
    if(bSet){
      rate = 1.0f/(micros() - periodStart);
      ++sum;
    }else{
      rate = -1.0f/(micros() - periodStart);
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

inline void Encoders::triggerB(bool& bSet){
  bSet = true;
}
