//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <Stepper.h>

const int stepsPerRevolution = 2040;

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup()
{
  myStepper.setSpeed(14);
}

void loop()
{
  myStepper.step(stepsPerRevolution);
  delay(1000);
  
  myStepper.step(-stepsPerRevolution);
  delay(1000); 
}
