#include <ESP8266WiFi.h>

#define RELAIS D2

void relais_setup()
{
    pinMode(RELAIS, OUTPUT);
}

void relaisON() 
{
    digitalWrite(RELAIS, HIGH);
}

void relaisOFF()
{
    digitalWrite(RELAIS, LOW);
}