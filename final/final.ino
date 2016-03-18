#include <Wire.h>
#include "Maxbotix.h"
//#include "TimerThree.h"
#include "Magnetometer.h"
//#include "DistanceSensor.h"
#include "MotorControl.h"
#include "Button.h"
#include "Compass.h"
#include "Navigation.h"

#define LEFT_ENCODER_PIN_A 19
#define LEFT_ENCODER_PIN_B 18
#define RIGHT_ENCODER_PIN_A 3
#define RIGHT_ENCODER_PIN_B 2

/*
MotorControl motors;
//Magnetometer magnetometer;
//DistanceSensor dsensor;
Button button;
*/

// interrupts must be in sketch. Encoders must be here
float left_rate, right_rate;
long left_sum, right_sum,
    left_periodStart, right_periodStart;
bool left_aSet, right_aSet,
    left_bSet, right_bSet;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin(); //Start I2C library
  Magnetometer magnetometer;
  Compass compass;
  Navigation navigation;
  //DistanceSensor dsensor;
  Button button;
  MotorControl motors(&right_rate, &left_rate);

  //must be done here because sketch functions must be referenced
  initialize_encoders();
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
  
  Serial.println("Starting tests");

  //while (true);
  
  //Turn the LED on
  pinMode(52, OUTPUT);
  digitalWrite(52, HIGH);

  Serial.println(navigation.smallestPositive(1,2));
  Serial.println(navigation.getExpectedDistanceToWall(0,0,0));

  /*
  button.waitForPush();
  Serial.println("Started motor");
  motors.forward(255);
  delay(1000);
  button.waitForPush();
  motors.stop();
  Serial.println("Stopped");
  while (true);
  */
}

void loop() {
  //Serial.println(compass.readAngle();
  delay(1000);
  //while (true);
}
void initialize_encoders() {
  left_aSet = false, right_aSet = false,
    left_bSet = false, right_bSet = false;
  left_rate = 0, right_rate = 0;
  left_sum = 0, right_sum = 0,
    left_periodStart = 0, right_periodStart = 0;

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


/*
void registerEncoderISRs() {
  attachInterrupt(
    digitalPinToInterrupt(LEFT_ENCODER_PIN_1),
    motorLeftEdge1Callback,
    FALLING);
    
  attachInterrupt(
    digitalPinToInterrupt(LEFT_ENCODER_PIN_2),
    motorLeftEdge2Callback,
    FALLING);
}


void motorLeftEdge1Callback() {
  //Serial.println("Left edge 1 fall");
  left1_count += 1;
}

void motorLeftEdge2Callback() {
  //Serial.println("Left edge 2 fall");
  left2_count += 1;
}

void timerStart() {
  Timer3.initialize(1000000); //Initialize timer1, set to 20Hz
  Timer3.attachInterrupt(timerCallback);
}

void timerCallback() {
  Serial.print("Left1: ");
  Serial.println(left1_count);
  Serial.print("Left2: ");
  Serial.println(left2_count);
}
*/

