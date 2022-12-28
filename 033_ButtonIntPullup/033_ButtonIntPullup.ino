//A full description of this module (and many others) can be downloaded at: https://eve_arduino

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(2, INPUT_PULLUP); //This line is only needed for internal pullup
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

