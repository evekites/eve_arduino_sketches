//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <Adafruit_GFX.h>
#include <SWTFT.h>
#include <TouchScreen.h>

#define YP A1
#define XM A2
#define YM 7
#define XP 6

#define TS_MINX 150
#define TS_MINY 120
#define TS_MAXX 920
#define TS_MAXY 940

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

#define  BLUE    0x001F
#define YELLOW  0xFFE0

SWTFT tft;

void setup(void) {
  Serial.begin(9600);
  tft.reset();
  tft.begin(tft.readID());
  delay(25);
  tft.fillScreen(BLUE);
  Serial.println(tft.width());
  Serial.println(tft.height());
}

void loop()
{
  TSPoint p = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  if (p.z > 10 && p.z < 1000)
  {
    p.x = map(p.x, TS_MINX, TS_MAXX, tft.width(), 0);
    p.y = map(p.y, TS_MINY, TS_MAXY, tft.height(), 0);
    tft.fillRect(p.x - 20, p.y - 20, 20, 20, YELLOW);
    Serial.print(p.x);
    Serial.print(", ");
    Serial.print(p.y);
    Serial.print(" pressure: ");
    Serial.println(p.z);
  }
}
