// #include "./effects/Rainbow.h"
#include "./effects/RainbowMoving.h"

boolean customColor = false;
RGB color = RGB(0, 0, 0);

void ledStripe_setup()
{
	pixels.begin();
	pixels.clear();

	pinMode(LED, OUTPUT);

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

void pulseBrightness(RGB rgb)
{
	for (int i = 1; i <= 100; i++)
	{
		int brightness = (254 / 2) * sin((2 * PI) / 100 * (i + 75)) + (254 / 2) + 1; // sinus wave
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
	pixels.setBrightness(254);

	if (customColor)
	{
		applyAllLeds(color);
	}
	else
	{
		// rainbow(LEDfade_duration); //? removed as it blocks other processes for too long
		rainbowMoving();
	}
}
