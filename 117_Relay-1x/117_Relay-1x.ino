//A full description of this module (and many others) can be downloaded at: https://eve_arduino

int Relay = 12;

void setup()
{
  pinMode(Relay, OUTPUT);
}

void loop()
{
  digitalWrite(Relay, HIGH);
  delay(3000);
  digitalWrite(Relay, LOW);
  delay(3000);
}

