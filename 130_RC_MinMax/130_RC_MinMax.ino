//A full description of this module (and many others) can be downloaded at: https://eve_arduino

const int CH1_pin = 2;
const int NrCH = 8;
int minimum = 20000;
int maximum = 0;

void setup()
{
  Serial.begin(115200);
  for (int channels = CH1_pin; channels < CH1_pin + NrCH; channels++)
  {
    Serial.println(channels);
    pinMode(CH1_pin, INPUT);
  }
}

void read_value(String channel_name, int channel_pin)
{
  int channel_value = pulseIn(channel_pin, LOW);
  if (channel_value < minimum)
  {
    minimum = channel_value;
  }
  if (channel_value > maximum)
  {
    maximum = channel_value;
  }
  Serial.print(channel_name);
  Serial.print(":");
  Serial.print (channel_value);
  Serial.print ("\t");
}

void loop()
{
  for (int channels = CH1_pin; channels < CH1_pin + NrCH; channels++)
  {
    read_value("CH", channels);
  }
  Serial.println();
  Serial.print(minimum);
  Serial.print(";");
  Serial.println(maximum);
}
