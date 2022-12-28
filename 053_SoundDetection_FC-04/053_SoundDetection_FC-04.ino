//A full description of this module (and many others) can be downloaded at: https://eve_arduino

int Led=13;
int Sound=2;

void setup()

{
  pinMode(Led, OUTPUT);
  pinMode(Sound, INPUT);
}

void loop()
{
  if (digitalRead(Sound) == LOW)
  {
    digitalWrite(Led, HIGH);
    delay(1000);
    digitalWrite(Led, LOW);
  }
}

