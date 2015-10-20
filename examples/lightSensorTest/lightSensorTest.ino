#include <LightSensor.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>

LightSensor lightSensor;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  lightSensor.init();
  lightSensor.setThreshold(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("The amount of light is: ");
  Serial.println(lightSensor.getBrightness());
  Serial.print("The room is dark: ");
  Serial.println(lightSensor.isDark());
  delay(1000);
}
