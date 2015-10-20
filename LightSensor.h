/*
LightSensor.h
*/

#ifndef LightSensor_h
#define LightSensor_h

#include "Arduino.h"
#include <Wire.h>

// Include libraries for the Adafruit LSM303 accelerometer
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>

class LightSensor
{
 public:

  LightSensor();
  bool init();
  bool isDark();
  void setThreshold(int t);
  int getBrightness();

 private:

  Adafruit_TSL2561_Unified _tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT);
  int _threshold = 500;
};

#endif
