//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include "SevSeg.h"

SevSeg sevseg;

void setup()
{
  byte numDigits = 4;
  byte digitPins[] = {13, 10, 9, 7};
  byte segmentPins[] = {12, 8, 5, 3, 2, 11, 6, 4};
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);
}

void loop() {
  static unsigned long timer = millis();
  static int deciSeconds = 0;

  if (millis() >= timer)
  {
    deciSeconds++;
    timer += 100;
    if (deciSeconds == 10000)
    {
      deciSeconds = 0;
    }
    sevseg.setNumber(deciSeconds, 1);
  }
  sevseg.refreshDisplay();
}
