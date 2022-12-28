//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

int pinCS = 10;

Max72xxPanel matrix = Max72xxPanel(pinCS, 1, 1);

int wait = 100; // In milliseconds

void setup()
{
  matrix.fillScreen(LOW);
  matrix.write();
}

void loop()
{
  for (int county=0;county<matrix.height();county++)
  {
    for (int countx=0;countx<matrix.width();countx++)
    {
      matrix.drawPixel(countx, county, HIGH);
      matrix.write();
      delay(wait);
      matrix.drawPixel(countx, county, LOW);
      matrix.write();
      delay(wait);
    }
  }
}

