//A full description of this module (and many others) can be downloaded at: https://eve_arduino

int RGBred = 11;
int RGBgreen = 10;
int RGBblue = 9;

void setup()
{
  pinMode(RGBred, OUTPUT);
  pinMode(RGBgreen, OUTPUT);
  pinMode(RGBblue, OUTPUT);
}

void loop()
{
  for (int redvalue=0;redvalue <=255;redvalue=redvalue+255)
  {
    for (int greenvalue=0;greenvalue <=255;greenvalue=greenvalue+255)
    {
        for (int bluevalue=0;bluevalue <=255;bluevalue=bluevalue+255)
        {
          RGB(redvalue,greenvalue,bluevalue);
          delay(500);
        }
    }
  }
}

void RGB(int red, int green, int blue)
{
  analogWrite(RGBred, red);
  analogWrite(RGBgreen, green);
  analogWrite(RGBblue, blue);  
}

