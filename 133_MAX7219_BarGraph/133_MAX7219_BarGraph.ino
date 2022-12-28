//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <LedControl.h>

#define NRCHIPS 1  //Nr of chips (=displays)
#define NRSEGMENTS 10 //Nr of segments in bar graph 
#define DIN 11
#define CLK 13
#define CS_LOAD 10

LedControl mydisplay = LedControl(DIN, CLK, CS_LOAD, NRCHIPS);

void setup() {
  mydisplay.shutdown(0, false);  // turns on display
  mydisplay.setIntensity(0, 4); // 15 = brightest
  mydisplay.clearDisplay(0);
}

void loop()
{
  for (int segment = 0; segment < NRSEGMENTS; segment++)
  {
    int rownr = segment / 8;
    int columnr = segment % 8;
    mydisplay.setLed(0, rownr, columnr, true);
    delay (100);
    mydisplay.setLed(0, rownr, columnr, false);
    delay(100);
  }
}
