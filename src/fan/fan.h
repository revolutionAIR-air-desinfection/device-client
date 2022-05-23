void fan_setup()
{
    pinMode(PWM, OUTPUT);
    pinMode(PWM_RELAIS, OUTPUT);
    Serial.println("[SETUP] FAN: DONE");
}

void setFanSpeed(unsigned int speed)
{
    digitalWrite(PWM_RELAIS, LOW);
    analogWrite(PWM, speed);
}

void fanOFF()
{
    digitalWrite(PWM_RELAIS, HIGH);
}
