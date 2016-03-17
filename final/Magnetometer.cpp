// DEPRECATING; USE COMPASS.CPP

#include "Magnetometer.h"
#include <Wire.h>

Magnetometer::Magnetometer() {
  //Put the HMC5883 IC into the correct operating mode
  Wire.beginTransmission(mag_address); //open communication with HMC5883
  Wire.write(0x02); //select mode register
  Wire.write(0x00); //continuous measurement mode
  Wire.endTransmission();

  x = y = z = 0;
  isUpsideDown = false;
}

void Magnetometer::getValues() {
  //Tell the HMC5883 where to begin reading data
  Wire.beginTransmission(mag_address);
  Wire.write(0x03); //select register 3, X MSB register
  Wire.endTransmission();
  
  //Read data from each axis, 2 registers per axis
  Wire.requestFrom(mag_address, 6);
  if(6<=Wire.available()){
    x = Wire.read()<<8; //X msb
    x |= Wire.read(); //X lsb
    z = Wire.read()<<8; //Z msb
    z |= Wire.read(); //Z lsb
    y = Wire.read()<<8; //Y msb
    y |= Wire.read(); //Y lsb
  }

  //Serial.println(x);
  //Serial.println(y);
  //Serial.println(z);
  //Serial.println("");
}
void Magnetometer::calibration() {}
void Magnetometer::getAngle() {}
void Magnetometer::setUpsideDown() {}

