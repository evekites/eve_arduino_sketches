//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 0;
const int colorG = 255;
const int colorB = 0;

void setup()
{
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  lcd.print("hello, world!");
  delay(1000);
}

void loop()
{
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
  delay(100);
}
