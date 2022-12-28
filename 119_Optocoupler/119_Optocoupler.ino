//A full description of this module (and many others) can be downloaded at: https://eve_arduino

int FLASH=4;
int LED=13;

void setup()
{
  pinMode(FLASH, OUTPUT);
  digitalWrite(FLASH, LOW);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  Serial.begin(9600); // open serial
  Serial.println("Press the spacebar followed by the Enter key");
}

void loop()
{
  int key;

  while (Serial.available() > 0)
  {
    int key = Serial.read();

    if (key = ' ')
    {
      digitalWrite(FLASH, HIGH);
      digitalWrite(LED, HIGH);
      Serial.println("Flash is triggered");
      delay(100);
      digitalWrite(FLASH, LOW);
      digitalWrite(LED, LOW);
      break;
    }
    else
    {
      Serial.println("Press the spacebar followed by the Enter key");
    }
  }
}
