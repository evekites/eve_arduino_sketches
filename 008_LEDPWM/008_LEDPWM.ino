//A full description of this module (and many others) can be downloaded at: https://eve_arduino

int led = 10;
int brightness = 0;
int fadeAmount = 5;

void setup()
{
  pinMode(led, OUTPUT);
}

void loop()
{
  analogWrite(led, brightness);
  brightness = brightness + fadeAmount;
  if (brightness == 0 || brightness == 255)
  {
    fadeAmount = -fadeAmount;
  }
  delay(10);
}

