//A full description of this module (and many others) can be downloaded at: https://eve_arduino

void setup()
{                
  for (int rownr=6;rownr<=13;rownr++)
  {
    pinMode(rownr,OUTPUT);
    digitalWrite(rownr,LOW);
  }
}

void loop()
{
  for (int rownr=6;rownr<=13;rownr++)
  {
    digitalWrite(rownr,HIGH);
    delay(200);
    digitalWrite(rownr,LOW);
  }
}

