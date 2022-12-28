#include <TheThingsNetwork.h>

#define loraSerial Serial1
#define debugSerial Serial
#define freqPlan TTN_FP_EU868

const char *appEui = "70B3D57ED0027053";
const char *appKey = "9CA2898977C9D15CF778E0244E572847";


TheThingsNetwork ttn(loraSerial, debugSerial, freqPlan);

void setup()
{
  loraSerial.begin(57600);
  debugSerial.begin(9600);
  delay(3000);
  ttn.onMessage(message);
  debugSerial.println("-- STATUS");
  ttn.showStatus();
  debugSerial.println("-- JOIN");
  ttn.join(appEui, appKey);
}

void loop()
{
  debugSerial.println("-- LOOP");
  byte payload[1];
  payload[0] = (digitalRead(LED_BUILTIN) == HIGH) ? 1 : 0;
  ttn.sendBytes(payload, sizeof(payload));
  delay(10000);
}

void message(const byte *payload, size_t length, port_t port)
{
  debugSerial.println("-- MESSAGE");
  if (length != 1)
  {
    ttn.sendBytes(payload, sizeof(payload));
    debugSerial.println("Bad message received, return message");
    return;
  }
  if (payload[0] == 0)
  {
    debugSerial.println("LED: off");
    digitalWrite(LED_BUILTIN, LOW);
  }
  else if (payload[0] == 1)
  {
    debugSerial.println("LED: on");
    digitalWrite(LED_BUILTIN, HIGH);
  }
}
