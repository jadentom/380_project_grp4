#include <Wire.h>
#include <EEPROM.h>
#include "Compass.h"
#include <Arduino.h>

#define COMPASS_ADRESS 0x1e

Compass::Compass() {
  byte p[256];
  int offset = 0;
  
  for(byte i = 0; i < sizeof(Compass_Calibration); ++i) {
    p[i] = EEPROM.read(COMPASS_ADRESS + offset++);
  }
  compassNormal = *((Compass_Calibration*)p);

  for(byte i = 0; i < sizeof(Compass_Calibration); ++i) {
    p[i] = EEPROM.read(COMPASS_ADRESS + offset++);
  }
  compassMotor = *((Compass_Calibration*)p);
};

float clamp (float inp) {
  if (inp > 1) {
    return 1;
  } else if (inp < -1) {
    return -1;
  }
  return inp;
}

float Compass::getAngle(bool motor, bool upright){
  int x,y; //double axis data
  readMagnetometer(&x, &y);

  float dx,dy;

  if (motor) {
    dx = (x - compassMotor.xshift) * compassMotor.xscale;
    dy = (y - compassMotor.yshift) * compassMotor.yscale;
  } else {
    dx = (x - compassNormal.xshift) * compassNormal.xscale;
    dy = (y - compassNormal.yshift) * compassNormal.yscale;
  }

  dx = clamp(dx);
  dy = clamp(dy);

  if(upright){
    return atan2(dx,dy);
  }else{
    return atan2(-dx,dy);
  }
}

byte Compass::readMagnetometer(int * x, int * y){
  Wire.beginTransmission(COMPASS_ADRESS);
  Wire.write(0x03);
  Wire.endTransmission();
 
  Wire.requestFrom(COMPASS_ADRESS, 6);
  if(6 > Wire.available()){
    return 0;
  }
  
  *x = Wire.read()<<8;
  *x |= Wire.read(); 
  
  Wire.read();
  Wire.read();
  
  *y = Wire.read()<<8; 
  *y |= Wire.read();

  return 1;
}

