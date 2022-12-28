//A full description of this module (and many others) can be downloaded at: https://eve_arduino

int FLASH=3;
int RELAY=4;
int LED=13;
int SOUND=2;

void setup()
{
  pinMode(FLASH, OUTPUT);
  digitalWrite(FLASH, LOW);
  pinMode(LED, OUTPUT);
  pinMode(RELAY, OUTPUT);
  pinMode(SOUND, INPUT);
  digitalWrite(LED, LOW);
  digitalWrite(RELAY, LOW);
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(SOUND)== LOW)
  {
    digitalWrite(FLASH, HIGH);
    digitalWrite(LED, HIGH);
    Serial.println("Flash is triggered");
    delay(100);
    digitalWrite(FLASH, LOW);
    digitalWrite(LED, LOW);
    digitalWrite(RELAY, HIGH);
    delay(100);
    digitalWrite(RELAY,LOW);
    delay(1000);
  }
}

