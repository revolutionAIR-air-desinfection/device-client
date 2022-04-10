#include <Adafruit_NeoPixel.h>

#define PIN D2
#define NUMPIXELS 34

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void applyAllLeds(int r, int g, int b) // apply color to all 34 leds on stripe
{
  for (int led = 0; led < NUMPIXELS; led++)
  {
    pixels.setPixelColor(led, pixels.Color(r, g, b));
  }
  pixels.show();
}

void rainbow(int DELAYVAL) // rainbow fading effect
{
  // devide by 3 because 3 for loops and
  // 255 because delay is applied 255 times per rgb color
  DELAYVAL = DELAYVAL / 3 / 255;

  // green
  for (int k = 0; k <= 255; k++)
  {
    applyAllLeds(k, 255 - k, 0);
    delay(DELAYVAL);
  }

  // red
  for (int k = 0; k <= 255; k++)
  {
    applyAllLeds(255 - k, 0, k);
    delay(DELAYVAL);
  }

  // blue
  for (int k = 0; k <= 255; k++)
  {
    applyAllLeds(0, k, 255 - k);
    delay(DELAYVAL);
  }

}
