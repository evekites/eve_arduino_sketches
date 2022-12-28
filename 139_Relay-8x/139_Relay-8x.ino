//A full description of this module (and many others) can be downloaded at: https://eve_arduino
#define RELAYS 8

void setup()
{
  for (int RELAY = 1; RELAY <= RELAYS; RELAY++)
  {
    pinMode(RELAY + 1, OUTPUT);
  }
}

void loop()
{
  for (int RELAY = 1; RELAY <= RELAYS; RELAY++)
  {
    digitalWrite(RELAY + 1, HIGH);
    delay(500);
    digitalWrite(RELAY + 1, LOW);
    delay(500);
  }
  delay(1500);
}
