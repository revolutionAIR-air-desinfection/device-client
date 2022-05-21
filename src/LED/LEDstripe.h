#include <Adafruit_NeoPixel.h>

#include "./effects/Rainbow.h"

#define NUMPIXELS 34

#define LEDfade_duration 10000 // time in ms the LED stripe needs to fade for 1 cycle
#define pulseDelay 10		   // delay for pulsing warnging/error LED indicator

// Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

boolean customColor = false;
unsigned int redValue;
unsigned int greenValue;
unsigned int blueValue;

void ledStripe_setup()
{
	pixels.begin();
	pixels.clear();

	pinMode(LED, OUTPUT);
}

//? method moved to "effects/rainbow.h"
// void applyAllLeds(int r, int g, int b){}

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

void setCustomColor(unsigned int r, unsigned int g, unsigned int b)
{
	// sets RGB value to be shown

	customColor = true;
	redValue = r;
	greenValue = g;
	blueValue = b;
}

void disableCustomColor() 
{
	// disables color and switches back to rainbow animation
	
	customColor	= false;
}

void ledStripe_loop()
{
	pixels.clear();
	pixels.setBrightness(254);

	if (customColor)
	{
		applyAllLeds(redValue, greenValue, blueValue);
	} else
	{
		rainbow(LEDfade_duration);
	}
}
