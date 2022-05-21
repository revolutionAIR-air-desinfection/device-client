//! UNABLE TO CONTROL FANS DUE TO MISSING PWM SUPPORT
#include <Arduino.h>

float speed_percentage; // percentage of fan speed varies from 0 to 100

void fan_setup()
{
    pinMode(PWM, OUTPUT);
}

void fan_loop()
{
    // PWM Value varries from 0 to 1023
    analogWrite(PWM, 1023 * (speed_percentage / 100));
    delay(2000);
}

void setFanSpeed(float percentage)
{
    percentage = speed_percentage; //! NEW FOR PWM
}

unsigned int getRPM()
{
    // TODO untested method
    return analogRead(RPM); //! NEW FOR PWM
}

void fanON() // TODO deprecated
{
    speed_percentage = 100; //! NEW FOR PWM
    analogWrite(PWM, 1023);
}

void fanOFF() // TODO deprecated
{
    speed_percentage = 0; //! NEW FOR PWM
    analogWrite(PWM, 0);
}
