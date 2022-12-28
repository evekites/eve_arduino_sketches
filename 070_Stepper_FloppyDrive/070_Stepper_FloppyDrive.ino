//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#define DELAY 1200
#define STEPS 200

int dir_pin = 12;
int step_pin = 13;

void setup()
{

  pinMode(dir_pin, OUTPUT);
  pinMode(step_pin, OUTPUT);
}

void loop()
{
  delay(1);
  digitalWrite(dir_pin, HIGH);
  delay(1);
  perform_step(STEPS);
  delay(500);
  digitalWrite(dir_pin, LOW);
  delay(1);
  perform_step(STEPS);
  delay(500);
}

void perform_step(long steps)
{
  for (long i = 0; i < steps; i++)
  {
    digitalWrite(step_pin, LOW);
    delayMicroseconds(100);
    digitalWrite(step_pin, HIGH);
    delayMicroseconds(DELAY);
  }
  digitalWrite(step_pin, LOW);
}

