#include <Adafruit_NeoPixel.h>

#define PIN D2
#define NUMPIXELS 34

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//? ============== testing ==============
#define BTN D0
#define RELAIS D1
boolean state = false;

void applyAllLeds(int r, int g, int b) // apply color to all 34 leds on stripe
{
  for (int led = 0; led < NUMPIXELS; led++)
  {
    pixels.setPixelColor(led, pixels.Color(r, g, b));
  }
  pixels.show();

  //? ============== testing ==============
  if (digitalRead(BTN))
  {
    state = !state;
    digitalWrite(RELAIS, state);
    digitalWrite(D3, !state);
  }
}

void rainbow(int DELAYVAL) // a cool rainbow fading effect
{
  // devide by 3 because 3 for loops and
  // 255 because delay is applied 255 times per rgb color
  DELAYVAL = DELAYVAL / 3 / 255;

  for (int k = 0; k <= 255; k++) // green
  {
    applyAllLeds(k, 255 - k, 0);
    delay(DELAYVAL);
  }


  for (int k = 0; k <= 255; k++) // red
  {
    applyAllLeds(255 - k, 0, k);
    delay(DELAYVAL);
  }


  for (int k = 0; k <= 255; k++) // blue
  {
    applyAllLeds(0, k, 255 - k);
    delay(DELAYVAL);
  }

}