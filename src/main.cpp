#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// LED stripe stuff
#include <LEDstripe.h>
#define LEDfade_duration 40000 // time in ms the LED stripe needs to fade for 1 cycle

void setup()
{
    // general stuff
    Serial.begin(9600);

    // LEDstripe stuff
    LEDstripe_setup();
}

void loop()
{
    // LEDstripe stuff
    Serial.print("loop");
    rainbow(LEDfade_duration);
}
