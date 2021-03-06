/*
	UNUSED METHOD AS DUE DO MISFUNCTIONAL "MULTITHREADING"
*/

#include "../../config.h"

void applyAllLeds(RGB rgb) // apply color to all 34 leds on stripe
{
	for (int led = 0; led < NUMPIXELS; led++)
	{
		pixels.setPixelColor(led, pixels.Color(rgb.r, rgb.g, rgb.b));
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
		applyAllLeds(RGB(k, 255 - k, 0));
		delay(DELAYVAL);
	}

	// red
	for (int k = 0; k <= 255; k++)
	{
		applyAllLeds(RGB(255 - k, 0, k));
		delay(DELAYVAL);
	}

	// blue
	for (int k = 0; k <= 255; k++)
	{
		applyAllLeds(RGB(0, k, 255 - k));
		delay(DELAYVAL);
	}
}
