//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

SSD1306AsciiWire oled;
SSD1306AsciiWire oled2;


void setup()
{
  Wire.begin();
  Wire.setClock(400000L);

  oled.begin(&Adafruit128x32, 0x3C);

  oled.setFont(Adafruit5x7);

  oled.displayRemap(false);
  oled.clear();
  oled.set1X();
  oled.println("Top");
  oled.setRow(7);
  oled.println("Bottom line");
}

void loop()
{
}
