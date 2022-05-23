#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(TEMPERATURE);        // KY-001 Signal pin is connected to Arduino pin 8
DallasTemperature sensors(&oneWire); // create DallasTemperature object and pass oneWire object as parameter

float getTemperature()
{
    sensors.requestTemperatures();
    return sensors.getTempCByIndex(0);
}

void temperature_setup()
{
    sensors.begin();
    Serial.println("[SETUP] TEMPERATURE: DONE");
}
