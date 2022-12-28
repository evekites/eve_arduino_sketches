//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

int pinCS = 10;

Max72xxPanel matrix = Max72xxPanel(pinCS, 1, 1);

void setup()
{
  matrix.setIntensity(14);
}

int wait = 50;
int inc = -2;

void loop()
{
  for ( int x = 0; x < matrix.width() - 1; x++ )
  {
    matrix.fillScreen(LOW);
    matrix.drawLine(x, 0, matrix.width() - 1 - x, matrix.height() - 1, HIGH);
    matrix.write(); // Send bitmap to display
    delay(wait);
  }
  for ( int y = 0; y < matrix.height() - 1; y++ )
  {
    matrix.fillScreen(LOW);
    matrix.drawLine(matrix.width() - 1, y, 0, matrix.height() - 1 - y, HIGH);
    matrix.write();
    delay(wait);
  }
  wait = wait + inc;
  if ( wait <= 0 ) inc = 2;
  if ( wait >= 50 ) inc = -2;
}
