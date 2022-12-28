//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include "Ultrasonic.h"

int DistanceSensorpin=2;

Ultrasonic ultrasonic(DistanceSensorpin);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  long RangeInCentimeters;
  RangeInCentimeters = ultrasonic.MeasureInCentimeters();
  delay(150);
  Serial.print("The distance is: ");
  Serial.println(RangeInCentimeters);
}

