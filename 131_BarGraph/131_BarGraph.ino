//A full description of this module (and many others) can be downloaded at: https://eve_arduino

void setup() {
  for (int LED = 1; LED <= 10; LED++)
  {
    pinMode(LED + 1, OUTPUT);
  }
}

void loop() {
  for (int LED = 1; LED <= 10; LED++)
  {
    digitalWrite(LED + 1, HIGH);
    delay(100);
    digitalWrite(LED + 1, LOW);
    delay(100);
  }
}
