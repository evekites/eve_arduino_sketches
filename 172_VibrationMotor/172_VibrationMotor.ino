#define VIBRATIONMOTOR 9

void setup() {
  pinMode(VIBRATIONMOTOR, OUTPUT);
}

void loop() {
  digitalWrite(VIBRATIONMOTOR, HIGH);
  delay(3000);
  digitalWrite(VIBRATIONMOTOR, LOW);
  delay(1000);
}
