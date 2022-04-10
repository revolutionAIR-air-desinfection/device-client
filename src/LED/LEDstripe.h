#include <Adafruit_NeoPixel.h>

// #include <LED/effects/rainbow.h>
#include "../LED/effects/rainbow.h"

// #include <LEDeffects/rainbowMoving.h> coming soon ...

#define PIN D2 // LED strip
#define NUMPIXELS 34

#define LEDfade_duration 10000 // time in ms the LED stripe needs to fade for 1 cycle
#define pulseDelay 10         // delay for pulsing warnging/error LED indicator

// Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void LEDstripe_setup()
{
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pixels.begin();
  pixels.clear();

  pinMode(PIN, OUTPUT);
}

// void applyAllLeds(int r, int g, int b) // apply color to all 34 leds on stripe
// {
//   for (int led = 0; led < NUMPIXELS; led++)
//   {
//     pixels.setPixelColor(led, pixels.Color(r, g, b));
//   }
//   pixels.show();
// }

void pulseBrightness(int r, int g, int b)
{
  for (int i = 1; i <= 100; i++)
  {
    int brightness = (254 / 2) * sin((2 * PI) / 100 * (i + 75)) + (254 / 2) + 1; // sinus wave
    pixels.setBrightness(brightness);
    applyAllLeds(r, g, b);
    delay(pulseDelay);
  }
}

void LEDstripe_loop()
{
  pixels.clear();
  pixels.setBrightness(254);
  // rainbow(LEDfade_duration);
  
}
