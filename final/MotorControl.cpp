#include "MotorControl.h"
#include <Arduino.h>

// Pins - Digital Pins (Controls Direction)
#define LEFT_DIGITAL_PIN 44
#define RIGHT_DIGITAL_PIN 42

// Pins - PWM Pins (Controls Speed)
#define  LEFT_PWM_PIN 5
#define RIGHT_PWM_PIN 4

MotorControl::MotorControl() {
  pinMode(LEFT_DIGITAL_PIN, OUTPUT);
  pinMode(RIGHT_DIGITAL_PIN, OUTPUT);
  pinMode(LEFT_PWM_PIN, OUTPUT);
  pinMode(RIGHT_PWM_PIN, OUTPUT);
}

void MotorControl::spinLeft(int speed) {
  if (isUpsideDown) {speed *= -1;}
  if (speed >= 0) {
    speed = 255 - speed;
    digitalWrite(LEFT_DIGITAL_PIN, HIGH);
  } else {
    speed *= -1;
    digitalWrite(LEFT_DIGITAL_PIN, LOW);
  }
  analogWrite(LEFT_PWM_PIN, speed);
}

void MotorControl::spinRight(int speed) {
  if (isUpsideDown) {speed *= -1;}
  if (speed >= 0) {
    digitalWrite(RIGHT_DIGITAL_PIN, LOW);
  } else {
    speed = 255 + speed;
    digitalWrite(RIGHT_DIGITAL_PIN, HIGH);
  }
  analogWrite(RIGHT_PWM_PIN, speed);
}

void MotorControl::spinCW(int speed) {
  spinRight(-speed);
  spinLeft(speed);
}
  
void MotorControl::spinCCW(int speed){
  spinCW(-speed);
}
  
void MotorControl::forward(int speed) {
  spinLeft(speed);
  spinRight(speed);
}
  
void MotorControl::backward(int speed){
  forward(-speed);
}
  
void MotorControl::stop(){
  spinRight(0);
  spinLeft(0);
}

