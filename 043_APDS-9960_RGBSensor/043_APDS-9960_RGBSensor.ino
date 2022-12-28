//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <Wire.h>
#include <SparkFun_APDS9960.h>

SparkFun_APDS9960 apds = SparkFun_APDS9960();
uint16_t ambient_light = 0;
uint16_t red_light = 0;
uint16_t green_light = 0;
uint16_t blue_light = 0;

void setup()
{
  Serial.begin(9600);
  apds.init();
  apds.enableLightSensor(false);
  delay(500);
}

void loop()
{
  apds.readAmbientLight(ambient_light);
  apds.readRedLight(red_light);
  apds.readGreenLight(green_light);
  apds.readBlueLight(blue_light);
  Serial.print("Ambient: ");
  Serial.print(ambient_light);
  Serial.print(" Red: ");
  Serial.print(red_light);
  Serial.print(" Green: ");
  Serial.print(green_light);
  Serial.print(" Blue: ");
  Serial.println(blue_light);
  delay(1000);
}

