//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

void setup()
{
  lcd.begin(16, 2);
  lcd.print("hello, world!");
  delay(1000);
}

void loop()
{
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
  delay(100);
}
