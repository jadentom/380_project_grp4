#include "TiltSensor.h"
#include <Arduino.h>

// For the tilt sensor pin
const int TILT_SENSOR_PIN = 0;
const int SAMPLING_PERIOD = 50; // [ms]
const int N_SAMPLES = 5;
const bool UPSIDE_DOWN_READING = HIGH;

TiltSensor::TiltSensor() {
  pinMode(TILT_SENSOR_PIN, INPUT_PULLUP);
}

bool TiltSensor::isUpsideDown() {
  int n_flipped = 0;
  for (int i = 0; i < N_SAMPLES; i++) {
    if (digitalRead(TILT_SENSOR_PIN) == UPSIDE_DOWN_READING) {
      n_flipped += 1;
    }
  }
  if (n_flipped > (int)(N_SAMPLES/2)) {
    return true;
  }
  return false;
}

