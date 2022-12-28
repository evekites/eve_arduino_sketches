#include "BasicStepperDriver.h"

#define X_MOTOR_STEPS 320
#define X_RPM 20

#define X_MICROSTEPS 1

#define X_DIR 5
#define X_STEP 2
#define ENABLE 8
BasicStepperDriver X_stepper(X_MOTOR_STEPS, X_DIR, X_STEP);

void setup()
{
  pinMode (ENABLE, OUTPUT);
  digitalWrite (ENABLE, LOW);
  X_stepper.begin(X_RPM, X_MICROSTEPS);
}

void loop()
{
  X_stepper.rotate(360);
  delay(2000);
  X_stepper.move(-X_MOTOR_STEPS * X_MICROSTEPS);
  X_stepper.disable();
  delay(2000);
}
