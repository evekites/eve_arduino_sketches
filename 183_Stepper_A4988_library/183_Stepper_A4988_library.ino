#include "BasicStepperDriver.h"

#define MOTOR_STEPS 200
#define RPM 20

#define MICROSTEPS 1

#define DIR 2
#define STEP 3
BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP);

void setup()
{
    stepper.begin(RPM, MICROSTEPS);
}

void loop()
{
    stepper.rotate(1200);
    stepper.disable();
    delay(5000);
}
