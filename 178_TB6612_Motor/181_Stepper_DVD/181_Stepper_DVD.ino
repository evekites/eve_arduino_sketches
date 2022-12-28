#include <Stepper.h>

const int stepsPerRevolution = 240;

Stepper myStepper(stepsPerRevolution, 4, 5, 6, 7);

void setup()
{
  myStepper.setSpeed(200);
}

void loop()
{
  myStepper.step(stepsPerRevolution);
  myStepper.step(-stepsPerRevolution);
  delay(2000);
}
