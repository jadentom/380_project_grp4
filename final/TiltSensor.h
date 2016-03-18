#ifndef TILT_SENSOR_H
#define TILT_SENSOR_H

/*include <Arduino.h>
// For the tilt sensor pin
const int TILT_SENSOR_PIN = 0;
const int SAMPLING_PERIOD = 50; // [ms]
const int N_SAMPLES = 5;
const bool HIGH_VALUE = HIGH;
*/

class TiltSensor {
  public:
    TiltSensor();
    bool isUpsideDown();
};

extern TiltSensor tilt_sensor;

#endif
