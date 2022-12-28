//A full description of this module (and many others) can be downloaded at: https://eve_arduino
#include <TM1638.h>

TM1638 module(8, 9, 7);

long previousMillis = 0;
long interval = 10;
long countdown = 1000; //ms

void setup()
{
}

void loop()
{
  for (int count = countdown; count >= 0; count--)
  {
    //non-blocking delay
    previousMillis = millis();
    while (millis() - previousMillis < interval)
    {
      module.setDisplayToDecNumber(count, 2, false);;
    }
  }
  module.clearDisplay();
  while (1)
  {
    module.setDisplayToString(String("BOOH"), 0, 2);
  }
}
