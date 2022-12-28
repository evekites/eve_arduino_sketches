//A full description of this module (and many others) can be downloaded at: https://eve_arduino

int ledPin = 13;
int pirPin = 7;

int pirValue; 

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  digitalWrite(ledPin, LOW);
}

void loop()
{
  pirValue = digitalRead(pirPin);
  digitalWrite(ledPin, pirValue);
}

