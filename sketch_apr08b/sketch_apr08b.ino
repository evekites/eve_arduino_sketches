#include "LIS3DHTR.h"
LIS3DHTR<TwoWire> ThreeAxis;
#include <U8x8lib.h>

U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE);

int xcoord = 0;
int ycoord = 0;

void setup() {
  Serial.begin(9600);
  ThreeAxis.begin(Wire, 0x19); //IIC init
  delay(100);
  ThreeAxis.setOutputDataRate(LIS3DHTR_DATARATE_50HZ);
  u8x8.begin();
  u8x8.setFlipMode(1);
  u8x8.setFont(u8x8_font_chroma48medium8_r);
}

void loop() {
  float Y = ThreeAxis.getAccelerationX();
  float X = ThreeAxis.getAccelerationY();

  if (X > 0.2)
  {
    xcoord++;
  }
  else if (X < -0.2)
  {
    xcoord--;
  }

  if (Y > 0.2)
  {
    ycoord++;
  }
  else if (Y < -0.2)
  {
    ycoord--;
  }
  u8x8.setCursor(xcoord, ycoord);
  u8x8.print("X");
  Serial.print(xcoord);
  Serial.print(",");
  Serial.println(ycoord);
  delay(100);
  u8x8.clear();
}
