//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <Stepper.h>

const int stepsPerRevolution = 200;

Stepper myStepper(stepsPerRevolution, 4, 5, 6, 7);

void setup()
{
  myStepper.setSpeed(280);
}

void loop()
{
  myStepper.step(stepsPerRevolution);
  delay(1000);
  
  myStepper.step(-stepsPerRevolution);
  delay(1000); 
}
