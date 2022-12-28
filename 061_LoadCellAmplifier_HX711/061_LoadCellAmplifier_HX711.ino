//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <HX711_ADC.h>
HX711_ADC LoadCell(3, 4);
long time_last_measurement;
float calibration_value=460.0;

void setup() 
{
  Serial.begin(9600);
  LoadCell.begin();
  long stabilisingtime = 2000;
  LoadCell.start(stabilisingtime);
  LoadCell.setCalFactor(calibration_value);
  Serial.println("Tare is complete");
}

void loop() 
{
  LoadCell.update();
  if (millis() > time_last_measurement + 250)
  {
    int measurement = LoadCell.getData();
    Serial.print("Weight: ");
    Serial.println(measurement);
    time_last_measurement = millis();
  }
  if (Serial.available() > 0)
  {
    char inByte = Serial.read();
    if (inByte == 't') LoadCell.tareNoDelay();
  }
  if (LoadCell.getTareStatus() == true)
  {
    Serial.println("Tare complete");
  }
}

