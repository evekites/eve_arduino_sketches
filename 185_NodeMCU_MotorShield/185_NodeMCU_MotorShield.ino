#define BLYNK_PRINT Serial
#include  <ESP8266WiFi.h>
#include  <BlynkSimpleEsp8266.h>

char auth[] = "yuttxJXcAZE-JJqSSSKZx0zsd_eo2OC7";

char ssid[] = "wifi-slaap";
char pass[] = "1kh0uvanv33lk03kj3s!";

int PWMA = 4; //Right side
int PWMB = 5; //Left side
int DA = 2; //Right reverse
int DB = 0; //Left reverse

void setup() {
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DA, OUTPUT);
  pinMode(DB, OUTPUT);
}

void loop() {
  Blynk.run();

}


BLYNK_WRITE(V1)
{
  int x = param[0].asInt();
  int y = param[1].asInt();
  if (x == -1 && y == -1)
  { //Backward and Left
    digitalWrite(PWMA, LOW);
    digitalWrite(DA, LOW);

    digitalWrite(PWMB, HIGH);
    digitalWrite(DB, HIGH);
  }
  else if (x == -1 && y == 0)
  { //Left Turn
    analogWrite(PWMA, 450);
    digitalWrite(DA, HIGH);

    analogWrite(PWMB, 450);
    digitalWrite(DB, LOW);
  }
  else if (x == -1 && y == 1)
  { //Forward and Left
    digitalWrite(PWMA, LOW);
    digitalWrite(DA, LOW);

    digitalWrite(PWMB, HIGH);
    digitalWrite(DB, LOW);
  }
  else if (x == 0 && y == -1)
  { //Backward
    digitalWrite(PWMA, HIGH);
    digitalWrite(DA, HIGH);

    digitalWrite(PWMB, HIGH);
    digitalWrite(DB, HIGH);
  }
  else if (x == 0 && y == 0)
  { //Stay
    digitalWrite(PWMA, LOW);
    digitalWrite(DA, LOW);

    digitalWrite(PWMB, LOW);
    digitalWrite(DB, LOW);
  }
  else if (x == 0 && y == 1)
  { //Forward
    digitalWrite(PWMA, HIGH);
    digitalWrite(DA, LOW);

    digitalWrite(PWMB, HIGH);
    digitalWrite(DB, LOW);
  }
  else if (x == 1 && y == -1)
  { //Backward and Right
    digitalWrite(PWMA, HIGH);
    digitalWrite(DA, HIGH);

    digitalWrite(PWMB, LOW);
    digitalWrite(DB, LOW);
  }
  else if (x == 1 && y == 0)
  { //Right turn
    analogWrite(PWMA, 450);
    digitalWrite(DA, LOW);

    analogWrite(PWMB, 450);
    digitalWrite(DB, HIGH);
  }
  else if (x == 1 && y == 1)
  { //Forward and Right
    digitalWrite(PWMA, HIGH);
    digitalWrite(DA, LOW);

    digitalWrite(PWMB, LOW);
    digitalWrite(DB, LOW);
  }
}
