#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 10
#define NR_OF_MODULES 3

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
}

void loop(void)
{
  for (int count = 0; count < NR_OF_MODULES; count++)
  {
    sensors.requestTemperatures();
    Serial.print(sensors.getTempCByIndex(count));
    Serial.print(" ");
  }
  Serial.println();
  delay(1000);}
