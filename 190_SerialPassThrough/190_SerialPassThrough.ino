#include <SoftwareSerial.h>
SoftwareSerial BTSerial(5, 6); // Tx pin of module | Rx pin of module

void setup()
{
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(9600);
}
 
void loop()
{
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  if (Serial.available())
    BTSerial.write(Serial.read());
}
