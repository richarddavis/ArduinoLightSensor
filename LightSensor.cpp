#include "Arduino.h"

// Libraries for the Adafruit TCS34725 Light Sensor
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>
#include "LightSensor.h"

LightSensor::LightSensor()
{
}

bool LightSensor::init()
{
  _tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);
  /* Initialise the sensor */
  if (_tsl.begin()) {
    return true;
  } else {
    return false;
  }
  _tsl.enableAutoRange(true);
  _tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_13MS);
}

bool LightSensor::isDark() {
  sensors_event_t event;
  _tsl.getEvent(&event);
  if (event.light) {
    if (event.light >= _threshold) {
      return false;
    } else {
      return true;
    }
  }
}

void LightSensor::setThreshold(int t) {
  _threshold = t;
}

int LightSensor::getBrightness() {
  sensors_event_t event;
  _tsl.getEvent(&event);

  if (event.light) {
    return event.light;
  } else {
    return 0;
  }
}
