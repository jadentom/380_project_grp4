#ifndef MAGNETOMETER_H
#define MAGNETOMETER_H

// DEPRECATING; USE COMPASS.H

#define mag_address 0x1E

class Magnetometer
{
  public:
    //properties
    int x;
    int y;
    int z;
    bool isUpsideDown;
    
    //methods
    Magnetometer();
    void getValues();

    //TODO: later
    void calibration();
    void getAngle();
    void setUpsideDown();
};

extern Magnetometer magnetometer;

#endif
