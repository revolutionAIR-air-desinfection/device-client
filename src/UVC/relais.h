#include <Arduino.h>

void relais_setup()
{
    pinMode(RELAIS, OUTPUT);
    Serial.println("[SETUP] RELAIS: DONE");
}

void relaisON() 
{
    digitalWrite(RELAIS, HIGH);
}

void relaisOFF()
{
    digitalWrite(RELAIS, LOW);
}
