// #include "./effects/Rainbow.h"
#include "./effects/RainbowMoving.h"

boolean customColor = false;
RGB color = RGB(0, 0, 0);

void ledStripe_setup()
{
	pixels.begin();
	pixels_in.begin();

	pixels.clear();
	pixels_in.clear();

	pinMode(LED, OUTPUT);
	pinMode(LED_IN, OUTPUT);

	Serial.println("[SETUP] LEDSTRIPE: DONE");
}

void applyAllLeds(RGB rgb) // apply color to all 34 leds on stripe
{
	for (int led = 0; led < NUMPIXELS; led++)
	{
		pixels.setPixelColor(led, pixels.Color(rgb.r, rgb.g, rgb.b));
	}
	pixels.show();
}

void applyAllLedsIn(RGB rgb) // apply color to all 34 leds on stripe
{
	for (int led = 0; led < NUMPIXELS; led++)
	{
		pixels_in.setPixelColor(led, pixels_in.Color(rgb.r, rgb.g, rgb.b));
	}
	pixels_in.show();
}

double sineWave(double minValue, double maxValue, int percent)
{
	double amplitude = (maxValue - minValue) / 2.0;
	double yOffset = minValue + amplitude;
	double x = (double)percent / 100.0 * 2.0 * PI;
	double y = amplitude * sin(x) + yOffset;
	return y;
}

void pulseBrightness(RGB rgb)
{
	for (int i = 1; i <= 100; i++)
	{
		double brightness = sineWave(minBrightness * 100, maxBrightness * 100, i); // returns the value of the sine wave at 50% of the period between 0 and 100
		// int brightness = ((254 * maxBrightness) / 2) * sin((2 * PI) / 100 * (i + 75)) + ((254 * maxBrightness) / 2) + 1; // sinus wave
		pixels.setBrightness(brightness);
		applyAllLeds(rgb);
		delay(pulseDelay);
	}
}

void setCustomColor(RGB rgb)
{
	// sets RGB value to be shown

	customColor = true;
	color = rgb;
}

void disableCustomColor()
{
	// disables color and switches back to rainbow animation

	customColor = false;
}

void ledStripe_loop()
{
	pixels.clear();
	pixels_in.clear();

	pixels.setBrightness(254);
	pixels_in.setBrightness(254 * 0.3);

	applyAllLedsIn(RGB(112, 20, 254));
	pulseBrightness(RGB(0, 0, 254));
}
