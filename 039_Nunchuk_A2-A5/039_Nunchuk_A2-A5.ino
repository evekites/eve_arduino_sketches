//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include "Wire.h"
#include "Chukkie.h"

WiiChuckie chuck = WiiChuckie();

void setup() {
  Serial.begin(115200);
  chuck.begin();
  chuck.update();
}

void loop() {
  delay(20);
  chuck.update();

  Serial.print((int)chuck.readJoyX());
  Serial.print(", ");
  Serial.print((int)chuck.readJoyY());
  Serial.print(", ");
  Serial.print((int)chuck.readRoll());
  Serial.print(", ");
  Serial.print((int)chuck.readPitch());
  Serial.print(", ");
  Serial.print((int)chuck.readAccelX());
  Serial.print(", ");
  Serial.print((int)chuck.readAccelY());
  Serial.print(", ");
  Serial.print((int)chuck.readAccelZ());
  Serial.print(", ");
  Serial.print((int)chuck.buttonZ);
  Serial.print(", ");
  Serial.print((int)chuck.buttonC);

  Serial.println();
}
