//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <Adafruit_CircuitPlayground.h>

boolean LEDSTATUS = false;

void setup()
{
  CircuitPlayground.begin();
}

void loop()
{
  CircuitPlayground.clearPixels();
  if (CircuitPlayground.leftButton())
  {
    CircuitPlayground.redLED(LEDSTATUS = !LEDSTATUS);
    for (int nr = 0; nr < 10; nr++)
    {
      CircuitPlayground.setPixelColor(nr, 0, 255, 0);
    }
  }
  if (CircuitPlayground.rightButton())
  {
    CircuitPlayground.redLED(LEDSTATUS = !LEDSTATUS);
    for (int nr = 0; nr < 10; nr++)
    {
      CircuitPlayground.setPixelColor(nr, 255, 0, 0);
    }
  }
  delay(100);
}
