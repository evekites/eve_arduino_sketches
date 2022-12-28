//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <RcTrainer.h>
#define channels 6

RcTrainer tx;

void setup()
{
    Serial.begin(115200);  
}

void loop()
{
  int channel_nr;
  int channel_value;
  for (channel_nr = 0; channel_nr < channels; channel_nr++)
  {
    channel_value = tx.getChannel(channel_nr);
    Serial.print("CH" + String(channel_nr));
    Serial.print(":");
    Serial.print (channel_value);
    Serial.print (" | ");
  }
  Serial.println("");
}


