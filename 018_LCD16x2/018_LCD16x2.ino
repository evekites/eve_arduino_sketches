//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6 , 7);

void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Hello, world!");
  lcd.setCursor(0, 1);
  lcd.print("Arduino is nice!");
}

void loop()
{
}
