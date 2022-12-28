//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_STMPE610.h>

// This is calibration data for the raw touch data to the screen coordinates
#define TS_MINX 360
#define TS_MINY 265
#define TS_MAXX 3864
#define TS_MAXY 3929

#define STMPE_CS 8
Adafruit_STMPE610 ts = Adafruit_STMPE610(STMPE_CS);
#define TFT_CS 10
#define TFT_DC 9
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

void setup(void)
{
  Serial.begin(9600);
  tft.begin();
  if (!ts.begin())
  {
    Serial.println("Unable to start touchscreen.");
  }
  else
  {
    Serial.println("Touchscreen started.");
  }
  tft.fillScreen(ILI9341_BLUE);
}

void loop()
{
  if (!ts.bufferEmpty())
  {
    TS_Point p = ts.getPoint();
    int py = map(p.y, TS_MINY, TS_MAXY, 0, tft.height());
    int px = map(p.x, TS_MINX, TS_MAXX, 0, tft.width());
    tft.fillRect(px, py, 20, 20, ILI9341_YELLOW);
    Serial.print(px);
    Serial.print(" , ");
    Serial.println(py);
  }
}

