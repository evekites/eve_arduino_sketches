#include <ChainableLED.h>
#define NUM_LEDS  1

ChainableLED leds(7, 8, NUM_LEDS);

void setup()
{
}

float hue = 0.0;
boolean up = true;

void loop()
{
  for (byte i=0; i<NUM_LEDS; i++)
    leds.setColorHSB(i, hue, 1.0, 0.1);
    
  delay(50);
    
  if (up)
    hue+= 0.005;
  else
    hue-= 0.005;
    
  if (hue>=1.0 && up)
    up = false;
  else if (hue<=0.0 && !up)
    up = true;
}
