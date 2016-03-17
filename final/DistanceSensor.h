#include <Wire.h>
#include <Maxbotix.h>
#include <SparkFun_VL6180X.h>

class DistanceSensor {
  public:

    //properties
    VL6180x sensor;
    Maxbotix rangeSensorAD;

    //methods
    DistanceSensor();
    float getTof();
    float getUltrasonic();
    float getDistance();

};

extern DistanceSensor distance_sensor;

