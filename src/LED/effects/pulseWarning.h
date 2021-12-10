#include <LED/LEDstripe.h>

void WifiNotConnected()
{
  pulseBrightness(255, 255, 0); // yellow, 10ms timeout
}

void DeviceOpen() {
  pulseBrightness(255, 0, 0); // red, 10ms timeout
}
