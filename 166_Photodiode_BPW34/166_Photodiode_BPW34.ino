void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  if (sensorValue > 600)
  {
    Serial.println("Flash");
  }
}
