//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <Adafruit_NeoPixel.h>

#define PIN 7
#define PIXELS 30
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  uint32_t color;
  for (int count = 0; count < PIXELS; count++)
  {
    color = strip.Color(255 , 0, 0);
    strip.setPixelColor(count, color);
    strip.show();
    delay(100);
    color = strip.Color(0, 50, 0);
    strip.setPixelColor(count, color);
    strip.show();
    delay(100);    
  }
}
