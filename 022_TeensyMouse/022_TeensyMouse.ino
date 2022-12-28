//A full description of this module (and many others) can be downloaded at: https://eve_arduino

void setup()
{
}

void loop()
{
  Mouse.move(0, 127);
  delay(1000);

  Mouse.move(127, 0);
  delay(1000);

  Mouse.move(0, -127);
  delay(1000);

  Mouse.move(-127, 0);

  delay(5000);
}

