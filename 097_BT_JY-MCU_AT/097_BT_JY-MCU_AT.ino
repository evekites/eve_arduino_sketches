//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // Tx pin of hc06 module | Rx pin of module

void setup()
{
  Serial.begin(57600); // Speed depends on the Serial monitor settings
  Serial.println("Enter AT commands:");
  BTSerial.begin(38400);  // Speed depends on the module used JY-MCU: 38400
}
 
void loop()
{
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  if (Serial.available())
    BTSerial.write(Serial.read());
}
