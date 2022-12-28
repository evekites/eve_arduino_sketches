#include <TheThingsNetwork.h>

#define loraSerial Serial1
#define debugSerial Serial
#define freqPlan TTN_FP_EU868

const char *devAddr = "26011D9B";
const char *nwkSKey = "2661D7E372F8DC9D6A8C64F0A8E8A31C";
const char *appSKey = "07751B93E387268E1972339FFF45C560";

TheThingsNetwork ttn(loraSerial, debugSerial, freqPlan);

void setup()
{
  loraSerial.begin(57600);
  debugSerial.begin(9600);
  delay(3000);
  debugSerial.println("-- PERSONALIZE");
  ttn.personalize(devAddr, nwkSKey, appSKey);
  debugSerial.println("-- STATUS");
  ttn.showStatus();
}

void loop()
{
  debugSerial.println("-- LOOP");
  byte payload[1];
  payload[0] = map(analogRead(A0), 0, 1023, 0, 255);
  ttn.sendBytes(payload, sizeof(payload));
  delay(10000);
}
