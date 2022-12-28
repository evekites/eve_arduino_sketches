//A full description of this module (and many others) can be downloaded at: https://eve_arduino

const int TouchPin = 2;
const int ledPin = 13;
void setup()
{
  pinMode(TouchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  int sensorValue = digitalRead(TouchPin);
  if (sensorValue == 1)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}

