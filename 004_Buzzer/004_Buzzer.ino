//A full description of this module (and many others) can be downloaded at: https://eve_arduino

int speakerPin = 8;
int shortnote = 50;
int longnote = 200;
int interpunction = 200;

void playLetterO()
{
  for (int i = 1; i <=3; i++)
  {
    digitalWrite(speakerPin, HIGH);
    delay(longnote);
    digitalWrite(speakerPin, LOW);
    delay(longnote);
  }
  delay(interpunction);
}

void playLetterS()
{
  for (int i = 1; i <=3; i++)
  {
    digitalWrite(speakerPin, HIGH);
    delay(shortnote);
    digitalWrite(speakerPin, LOW);
    delay(shortnote);
  }
  delay(interpunction);
}

void setup()
{
  pinMode(speakerPin, OUTPUT);
}

void loop()
{
  playLetterS();
  playLetterO();
  playLetterS();
  delay(1000);
}

