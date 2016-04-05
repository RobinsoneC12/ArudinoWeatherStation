#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <BH1750.h>
#include <Adafruit_MPL115A2.h>
#include "sensors/TemperatureSensor.hpp"
#include "sensors/RainStatusSensor.hpp"

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
BH1750 lightMeter;
Adafruit_MPL115A2 barometer;
TemperatureSensor temperatureSensor(0);
RainStatusSensor rainStatusSensor(2);

float temperature;
bool rainStatus;
int lightLevel;
float pressure;

void getSensorData()
{
	temperature = temperatureSensor.readTemperature();
	rainStatus = rainStatusSensor.readRainStatus();
	lightLevel = lightMeter.readLightLevel();
	pressure = barometer.getPressure();
}