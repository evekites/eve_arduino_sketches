#include <TheThingsNetwork.h>

#define loraSerial Serial1
#define debugSerial Serial
#define freqPlan TTN_FP_EU868

const char *appEui = "70B3D57ED0027053";
const char *appKey = "F8DBA86EC0380258A959DF7BD8826249";

TheThingsNetwork ttn(loraSerial, debugSerial, freqPlan);

void setup()
{
  loraSerial.begin(57600);
  debugSerial.begin(9600);
  delay(3000);
  debugSerial.println("-- STATUS");
  ttn.showStatus();
  debugSerial.println("-- JOIN");
  ttn.join(appEui, appKey);
}

void loop()
{
  debugSerial.println("-- LOOP");
  byte payload[1];
  payload[0] = map(analogRead(A0),0,1023,0,255);
  ttn.sendBytes(payload, sizeof(payload));
  delay(60000);
}
