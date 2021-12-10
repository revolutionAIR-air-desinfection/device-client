#include <ESP8266WiFi.h>

#define PWM D7

void fan_setup()
{
    pinMode(PWM, OUTPUT); // needed ???
}

void fan_loop()
{
    // PWM Value varries from 0 to 1023
    Serial.println("10 % PWM");
    analogWrite(PWM, 102);
    delay(2000);

    Serial.println("20 % PWM");
    analogWrite(PWM, 205);
    delay(2000);

    Serial.println("40 % PWM");
    analogWrite(PWM, 410);
    delay(2000);

    Serial.println("70 % PWM");
    analogWrite(PWM, 714);
    delay(2000);

    Serial.println("100 % PWM");
    analogWrite(PWM, 1024);
    delay(2000);
}
