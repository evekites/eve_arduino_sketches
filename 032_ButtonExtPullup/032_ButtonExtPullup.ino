//A full description of this module (and many others) can be downloaded at: https://eve_arduino

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(2, INPUT); //This line is needed for external pullup/pulldown
}

void loop()
{
  int Buttonstate = digitalRead(2);
  if (Buttonstate == LOW) //When button is pressed, buttonstate == LOW!
  {
    digitalWrite(13, HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
  }
}

