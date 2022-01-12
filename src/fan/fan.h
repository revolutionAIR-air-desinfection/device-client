
#define PWM D7

void fan_setup()
{
    pinMode(PWM, OUTPUT);
}

void fan_loop(float percentage)
{
    // PWM Value varries from 0 to 1023
    analogWrite(PWM, 1024 * (percentage / 100));
    delay(2000);
}
