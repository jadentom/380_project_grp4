#include <Wire.h>
#include <EEPROM.h>
#include <Arduino.h>

#define COMPASS_ADRESS 0x1e

typedef struct{
  int xmin,xmax,ymin,ymax;
  float xscale,xshift,yscale,yshift;
} Compass_Calibration;

class Compass {
  public:
    // properties
    Compass_Calibration compassNormal;
    Compass_Calibration compassMotor;
    
    // methods
    Compass();
    float clamp(float inp);
    float getAngle(bool motor, bool upright);
    byte readMagnetometer(int * x, int * y);
};

extern Compass compass;

