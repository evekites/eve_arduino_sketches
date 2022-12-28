//A full description of this module (and many others) can be downloaded at: https://eve_arduino

const int PPM_pin = 2;
#define channels 8


void setup()
{
  Serial.begin(115200);
  pinMode(PPM_pin, INPUT);
}

void loop()
{
  int channel_nr;
  int channel_value;
  while (pulseIn(PPM_pin, LOW) < 5000)
  {
    //Wait for the beginning of the frame
  }
  for (channel_nr = 0; channel_nr <= channels - 1; channel_nr++)
  {
    channel_value = pulseIn(PPM_pin, LOW);
    Serial.print("CH" + String(channel_nr));
    Serial.print(":");
    Serial.print (channel_value);
    Serial.print (" | ");
  }
  Serial.println("");
  delay(300);
}


