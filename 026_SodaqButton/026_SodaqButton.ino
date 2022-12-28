//A full description of this module (and many others) can be downloaded at: https://eve_arduino

void setup()
{
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED_GREEN, OUTPUT);
}

void loop()
{
  int sensorVal = digitalRead(BUTTON);
  if (sensorVal == HIGH)
  {
    digitalWrite(LED_GREEN, HIGH);
  }
  else
  {
    digitalWrite(LED_GREEN, LOW);
  }
}

