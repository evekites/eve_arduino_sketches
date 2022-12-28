//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <SPI.h>
#include <epd2in7b.h>
#include <epdpaint.h>
#define COLORED     1
#define UNCOLORED   0
Epd epd;
unsigned char image[1024];

void setup() 
{
  Serial.begin(9600);
  if (epd.Init() != 0) {
    Serial.print("e-Paper init failed");
    return;
  }
  epd.ClearFrame();
}

void loop()
{
  Paint paint(image, 88  , 48);    //width should be the multiple of 8
  paint.Clear(COLORED);
  paint.DrawRectangle(30, 20, 80, 45 , UNCOLORED);
  paint.DrawStringAt(0, 0, "eve_arduino", &Font12, UNCOLORED);
  epd.TransmitPartialBlack(paint.GetImage(), 80 , 132, paint.GetWidth(), paint.GetHeight());
  epd.DisplayFrame();
  epd.Sleep();
  while(true)
  {
    
  }
}
