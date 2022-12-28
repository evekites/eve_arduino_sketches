#define DETECTOR 6

void setup() {
  // put your setup code here, to run once:
  pinMode(DETECTOR, INPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(DETECTOR)==HIGH)
  {
    Serial.println("Beam Detected");
  }  
}
