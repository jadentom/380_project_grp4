#include "MotorControl.h"
#include <Arduino.h>

// Pins - Digital Pins (Controls Direction)
#define LEFT_DIGITAL_PIN 44
#define RIGHT_DIGITAL_PIN 42

// Pins - PWM Pins (Controls Speed)
#define  LEFT_PWM_PIN 5
#define RIGHT_PWM_PIN 4

MotorControl::MotorControl(float* right_rate, float* left_rate) {
  this->right_rate = right_rate;
  this->left_rate = left_rate;
  pinMode(LEFT_DIGITAL_PIN, OUTPUT);
  pinMode(RIGHT_DIGITAL_PIN, OUTPUT);
  pinMode(LEFT_PWM_PIN, OUTPUT);
  pinMode(RIGHT_PWM_PIN, OUTPUT);
  kpl = 4;
  kpr = 4;
  axilCoff = 145 / 140;
}

void MotorControl::pidLeft(int speedTarget){
	float error = 0.40268456 * (*left_rate) - speedTarget;
	float u = error * kpl;
	if(u > 255){
		u = 255;
	}else if(u < -256){
		u = -256;
	}
	spinLeft(u + 0.5);
	
}
void MotorControl::pidRight(int speedTarget){
	float error = 0.40268456 * (*right_rate) - speedTarget;
	float u = error * kpr;
	if(u > 255){
		u = 255;
	}else if(u < -256){
		u = -256;
	}
	spinRight(u + 0.5);
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
  pidRight(-speed * axilCoff);
  pidLeft(speed * axilCoff);
}
  
void MotorControl::spinCCW(int speed){
  spinCW(-speed);
}
  
void MotorControl::forward(int speed) {
  pidLeft(speed);
  pidRight(speed);
}
  
void MotorControl::backward(int speed){
  forward(-speed);
}
  
void MotorControl::stop(){
  pidRight(0);
  pidLeft(0);
}

