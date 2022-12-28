//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <Wire.h>
#include "paj7620.h"

#define GES_REACTION_TIME    500
#define GES_ENTRY_TIME      800
#define GES_QUIT_TIME     1000

void setup()
{
  Serial.begin(9600);
  Serial.println("\nPAJ7620U2 TEST DEMO: Recognize 9 gestures.");
  uint8_t error = paj7620Init();
  Serial.println("Please input your gestures:\n");
}

void loop()
{
  uint8_t data = 0, data1 = 0, error;
  error = paj7620ReadReg(0x43, 1, &data);
  switch (data)
  {
    case GES_RIGHT_FLAG:
      Serial.println("Right");
      delay(GES_QUIT_TIME);
      break;

    case GES_LEFT_FLAG:
      Serial.println("Left");
      delay(GES_QUIT_TIME);
      break;

    case GES_UP_FLAG:
      Serial.println("Up");
      delay(GES_QUIT_TIME);
      break;

    case GES_DOWN_FLAG:
      Serial.println("Down");
      delay(GES_QUIT_TIME);
      break;

    case GES_CLOCKWISE_FLAG:
      Serial.println("Clockwise");
      break;


    case GES_COUNT_CLOCKWISE_FLAG:
      Serial.println("anti-clockwise");
      break;

    default:
      paj7620ReadReg(0x44, 1, &data1);
      if (data1 == GES_WAVE_FLAG)
      {
        Serial.println("wave");
      }
      break;
  }
  delay(100);
}

