//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv myirrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  myirrecv.enableIRIn(); // Start the receiver
}
void loop() {
  if (myirrecv.decode(&results)) {
    Serial.print(results.value, DEC);
    Serial.print("\t");
    Serial.println(results.value, HEX);
    myirrecv.resume(); // Receive the next value
  }
}
