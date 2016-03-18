#include <Wire.h>
#include "Maxbotix.h"
//#include "TimerThree.h"
#include "Magnetometer.h"
#include "DistanceSensor.h"
#include "MotorControl.h"
#include "Button.h"
#include "Compass.h"
#include "Navigation.h"
#include "Encoders.h"
#include "Fusion.h"

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
  DistanceSensor dsensor;
  Button button;
  MotorControl motors(&right_rate, &left_rate);
  Fusion fusion(&compass);

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
    digitalPinToInterrupt(RIGHT_ENCODER_PIN_A),
    rightTriggerA,
    CHANGE);
  attachInterrupt(
    digitalPinToInterrupt(RIGHT_ENCODER_PIN_B),
    rightTriggerB,
    RISING);
  
  Serial.println("Starting tests");
  pinMode(52, OUTPUT);
  digitalWrite(52, HIGH);

  //while (true);
  button.waitForPush();
  digitalWrite(52, LOW);

  /*
  //motors.forward(-40);
  delay(1000);
  while (digitalRead(26) == HIGH) {
    Serial.println("Here..");
    //motors.spinCCW(-40);
    //motors.forward(-5);
    //motors.pidRight(-5);
    //Serial.println(dsensor.getDistance());
    //Serial.println(compass.getMapAngle(false, false));
    //motors.spin
    Serial.println(fusion.fuse(&left_sum, &right_sum, false, true));
    delay(500);
  }
  Serial.println(left_sum);
  Serial.println(right_sum);
  delay(1000);
  //Turn the LED on
  digitalWrite(52, HIGH);
  motors.stop();
  
  while(true);
  button.waitForPush();
  */

  //TURN TO AN ANGLE
  
  float desired_angle = 0;
  float error = 0.25;
  //motors.spinCCW(-3);
  //motors.stop();
  while(true);
  delay(1000);
  while (digitalRead(26) == HIGH) {
    motors.spinCCW(-10);
    Serial.println(1000 * left_rate);
    Serial.println(1000 * right_rate);
    delay(500);
  }
  motors.stop();
  //while (abs(compass.getMapAngle(false, false) - desired_angle) > error) {
  //  Serial.println(compass.getMapAngle(false, false));
  //}
  //while (abs(fusion.fuse(&left_sum, &right_sum, false, false) - desired_angle) > error) {
  //  Serial.println(compass.getMapAngle(false, false));
  //}
  motors.stop();
  

  while(true);

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
void turnToAngle(int angle) {}
void driveForward(float speed) {}
void mapEnclosure() {
  int x,y;
  turnToAngle(-90);
  driveForward(5);
  while (dsensor.getDistance() < 40);
  turnToAngle(-90);
  y = dsensor.getDistance();

  turnToAngle(-180);
  x = dsensor.getDistance();
  //Map the environment
}*/

