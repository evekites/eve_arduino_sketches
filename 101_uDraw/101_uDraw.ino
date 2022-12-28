#include <Wire.h>

uint16_t x_raw;
uint16_t y_raw;
uint8_t pressure_raw;
uint8_t btnStylusUpper;
uint8_t btnStylusLower;
uint8_t btnHighPressure;
uint8_t hasChange = 0;
uint8_t reply[10];
uint8_t lastReply[10];
uint8_t firstRun = 1;

void setup() 
{
  Serial.begin(38400);
  Wire.begin();
  Wire.beginTransmission(0x52);
  Wire.write(0xF0);
  Wire.write(0x55);
  Wire.endTransmission();
  delay(100);
  Wire.beginTransmission(0x52);
  Wire.write(0xFB);
  Wire.write(0x00);
  Wire.endTransmission();
  delay(5);
}

void getDataFromTablet()
{
  Wire.beginTransmission(0x52);
  Wire.write(0x00);
  Wire.endTransmission();
  Wire.requestFrom(0x52, 6);
  hasChange = 0;
  unsigned long timeout = millis();
  for (int lp = 0; lp < 6; lp++)
  {
    while ( !Wire.available() )
    {
      if ( millis() - timeout > 2 )
      {
        return;
      }
    };
    reply[lp] = (uint8_t)Wire.read();
    if ( firstRun == 1 )
    {
      lastReply[lp] = reply[lp];
    } else {
      if (lastReply[lp] != reply[lp])
      {
        lastReply[lp] = reply[lp];
        hasChange = 1;
      }
    }
  }
  firstRun = 0;
  uint8_t x_nibble_one = reply[2] & 0x0F;  // 2R
  uint8_t x_nibble_two = reply[0] >> 4;    // 0L
  uint8_t x_nibble_three = reply[0] & 0x0F;// 0R
  uint8_t y_nibble_one = reply[2] >> 4;    // 2L
  uint8_t y_nibble_two = reply[1] >> 4;    // 1L
  uint8_t y_nibble_three = reply[1] & 0x0F;// 1R
  x_raw = (uint16_t)x_nibble_one << 8 | (uint16_t)x_nibble_two << 4 | (uint16_t)x_nibble_three;
  y_raw = (uint16_t)y_nibble_one << 8 | (uint16_t)y_nibble_two << 4 | (uint16_t)y_nibble_three;
  pressure_raw = reply[3];
  btnStylusUpper = !(reply[5] & 1);
  btnStylusLower = !(reply[5] >> 1 & 1);
  btnHighPressure = (reply[5] >> 2 & 1);
}

void sendData()
{
  if ( hasChange == 0 )
  {
    return;
  }
  Serial.print(x_raw);
  Serial.print(" ");
  Serial.print(y_raw);
  Serial.print(" ");
  Serial.print(pressure_raw); //Tip pressure value
  Serial.print(" ");
  Serial.print(btnHighPressure); //Tip pressure high
  Serial.print(" ");
  Serial.print(btnStylusLower); //Lower button
  Serial.print(" ");
  Serial.print(btnStylusUpper); //Upper button
  Serial.println("");
  Serial.flush();
}

void loop()
{
  getDataFromTablet();
  sendData();
}
