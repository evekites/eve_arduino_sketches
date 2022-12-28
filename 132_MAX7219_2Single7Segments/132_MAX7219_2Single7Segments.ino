//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <LedControl.h>

#define NRCHIPS 1  //Nr of chips (=displays)
#define NRDIGITS 1 //Nr of digits per chip 
#define DIN 11
#define CLK 13
#define CS_LOAD 10

LedControl mydisplay = LedControl(DIN, CLK, CS_LOAD, NRCHIPS);
char character[15] = {'A', 'B', 'C', 'D', 'E', 'F', 'H', 'L', 'n', 'o', 'P', ' ', '-', '_', '.'};

void setup() 
{
  mydisplay.shutdown(0, false);  // turns on display
  mydisplay.setIntensity(0, 15); // 15 = brightest
  mydisplay.clearDisplay(0);
}

void loop()
{
  for (int digit = 0; digit < NRDIGITS; digit++)
  {
    for (int count = 0; count < 10; count++)
    {
      mydisplay.setDigit(0, digit, count, false);
      delay(400);
    }
    for (int count = 0; count < 15; count++)
    {
      mydisplay.setChar(0, digit, character[count], false);
      delay(400);
    }
  }
}
