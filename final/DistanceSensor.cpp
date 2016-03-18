#include "DistanceSensor.h"
#include <Wire.h>

#define VL6180X_ADDRESS 0x29 // For the IR ToF range finder
#define ULTRASONIC_AD_PIN 0

DistanceSensor::DistanceSensor()
  :sensor(VL6180X_ADDRESS),
  rangeSensorAD(ULTRASONIC_AD_PIN, Maxbotix::AN, Maxbotix::LV) {

  // IR ToF range finder setup
  if(sensor.VL6180xInit() != 0){
    Serial.println("FAILED TO INITALIZE TOF"); //Initialize device and check for errors
  };
  sensor.VL6180xDefautSettings(); //Load default settings to get started.
  
}

float DistanceSensor::getTof() {
  float d = ((float)sensor.getDistance()) / 10;
  return d;
}

float DistanceSensor::getUltrasonic() {
  float d = rangeSensorAD.getRange();
  return d;
}

float DistanceSensor::getDistance() {
  float tof = getTof();
  if (tof > 25.0) {
    return tof;
  }
  return getUltrasonic();
}

