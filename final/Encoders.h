#ifndef ENCODERS_H
#define ENCODERS_H

#define LEFT_ENCODER_PIN_A 3
#define LEFT_ENCODER_PIN_B 2
#define RIGHT_ENCODER_PIN_A 19
#define RIGHT_ENCODER_PIN_B 18

// interrupts must be in sketch. Encoders must be here
float left_rate, right_rate;
long left_sum, right_sum,
    left_periodStart, right_periodStart;
bool left_aSet, right_aSet,
    left_bSet, right_bSet;
void initialize_encoders() {
  left_aSet = false, right_aSet = false,
    left_bSet = false, right_bSet = false;
  left_rate = 0, right_rate = 0;
  left_sum = 0, right_sum = 0,
    left_periodStart = 0, right_periodStart = 0;

}

inline void triggerA(bool& aSet, bool& bSet, int pinA, long& periodStart, long& sum, float& rate){
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

inline void triggerB(bool& bSet){
  bSet = true;
}

inline void leftTriggerA() {
  triggerA(left_aSet, left_bSet, LEFT_ENCODER_PIN_A, left_periodStart, left_sum, left_rate);
}

inline void leftTriggerB() {
  triggerB(left_bSet);
}

inline void rightTriggerA() {
  triggerA(right_aSet, right_bSet, RIGHT_ENCODER_PIN_A, right_periodStart, right_sum, right_rate);
}

inline void rightTriggerB() {
  triggerB(right_bSet);
}

#endif
