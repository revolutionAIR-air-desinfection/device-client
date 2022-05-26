//? get output of PIN
int digitalReadOutputPin(uint8_t pin)
{
  uint8_t bit = digitalPinToBitMask(pin);
  uint8_t port = digitalPinToPort(pin);
  if (port == NOT_A_PIN) 
    return LOW;

  return (*portOutputRegister(port) & bit) ? HIGH : LOW;
}

void fan_setup()
{
    pinMode(PWM, OUTPUT);
    pinMode(PWM_RELAIS, OUTPUT);
    Serial.println("[SETUP] FAN: DONE");
}

void fanON()
{
    digitalWrite(PWM_RELAIS, HIGH);
    analogWrite(PWM, 255);
}

void fanOFF()
{
    digitalWrite(PWM_RELAIS, LOW);
}

void setFanSpeed(unsigned int speed)
{
    if (speed == 0)
    {
        fanOFF();
    }
    else
    {
        if (digitalReadOutputPin(PWM_RELAIS) == LOW)
        {
            digitalWrite(PWM_RELAIS, HIGH);
        }
        
        analogWrite(PWM, speed * 2.5);
    }
}
