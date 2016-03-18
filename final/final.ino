#include <Wire.h>
#include "Maxbotix.h"
//#include "TimerThree.h"
#include "Magnetometer.h"
//#include "DistanceSensor.h"
#include "MotorControl.h"
#include "Button.h"
#include "Compass.h"
#include "Navigation.h"
#include "Encoders.h"

/*
MotorControl motors;
//Magnetometer magnetometer;
//DistanceSensor dsensor;
Button button;
*/

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

