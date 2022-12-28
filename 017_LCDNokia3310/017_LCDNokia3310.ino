//A full description of this module (and many others) can be downloaded at: https://eve_arduino

int CLK=3;
int DIN=4;
int DC=5;
int CE=6;
int RST=7;
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
Adafruit_PCD8544 display = Adafruit_PCD8544(CLK, DIN, DC, CE, RST);

void setup()
{
  display.begin();         
  display.setContrast(50);
}

void loop() 
{
  display.clearDisplay();
  display.setCursor(10,18); 
  display.println("PCD8544 test"); 
  display.display();
  delay(1000);
  display.clearDisplay();
  display.drawCircle(42, 23, 23, BLACK);
  display.display();
  delay(1000);
}

