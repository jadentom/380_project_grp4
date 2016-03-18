#ifndef COMPASS_H
#define COMPASS_H

#include <Wire.h>
#include <EEPROM.h>
#include <Arduino.h>

#define COMPASS_ADRESS 0x1e

typedef struct{
  int xmin,xmax,ymin,ymax;
  float xscale,xshift,yscale,yshift;
  float origin_angle;
} Compass_Calibration;

class Compass {
  public:
    // properties
    Compass_Calibration compassNormal;
    Compass_Calibration compassMotor;
    
    // methods
    Compass();
    float clamp(float inp);
    float getMapAngle(bool motor, bool upright);
    float getAngle(bool motor, bool upright);
    byte readMagnetometer(int * x, int * y);
};

extern Compass compass;

#endif
