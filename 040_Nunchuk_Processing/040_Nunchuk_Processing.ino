//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include "Wire.h"
#include "Chukkie.h"

// You can choose whether you want to use the joystick X, Y or Roll, Pitch
boolean Joystick = true;

WiiChuckie chuck = WiiChuckie();

void setup() {
  Serial.begin(115200);
  chuck.begin();
  chuck.update();
}

void loop() {
  delay(20);
  chuck.update();

  if (Joystick)
  {
    Serial.print((int)chuck.readJoyX());
    Serial.print(", ");
    Serial.print((int)chuck.readJoyY());
  }
  else
  {
    Serial.print((int)chuck.readRoll());
    Serial.print(", ");
    Serial.print((int)chuck.readPitch());
  }
  Serial.println();
}
