//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <stdio.h>
#include <wiringPi.h>

const int pwmPin = 18;
const int ledPin = 23;
const int butPin = 22;

const int pwmValue = 75;

int main(void)
{
  wiringPiSetupGpio();

  pinMode(pwmPin, PWM_OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(butPin, INPUT);
  pullUpDnControl(butPin, PUD_UP);

  printf("blinker is running! Press CTRL+C to quit.");

  // Loop (while(1)):
  while (1)
  {
    if (digitalRead(butPin))
    {
      pwmWrite(pwmPin, pwmValue);
      digitalWrite(ledPin, LOW);
    }
    else
    {
      pwmWrite(pwmPin, 1024 - pwmValue);
      digitalWrite(ledPin, HIGH);
      delay(75); // Wait 75ms
      digitalWrite(ledPin, LOW);
      delay(75); // Wait 75ms again
    }
  }

  return 0;
}
