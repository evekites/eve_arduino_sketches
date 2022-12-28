//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include <Adafruit_Sensor.h>
#include <DHT_U.h>

#define DHTPIN            A2
#define DHTTYPE           DHT11

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void setup() {
  Serial.begin(9600);
  delay(5000);
  dht.begin();
  Serial.println("DHTxx Unified Sensor Example");
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.println("------------------------------------");
  Serial.println("Temperature specs");
  Serial.print  ("Max Value:    "); Serial.println(sensor.max_value);
  Serial.print  ("Min Value:    "); Serial.println(sensor.min_value);
  Serial.print  ("Resolution:   "); Serial.println(sensor.resolution);
  dht.humidity().getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.println("Humidity specs");
  Serial.print  ("Max Value:    "); Serial.println(sensor.max_value);
  Serial.print  ("Min Value:    "); Serial.println(sensor.min_value);
  Serial.print  ("Resolution:   "); Serial.println(sensor.resolution);
  Serial.println("------------------------------------");
  delayMS = sensor.min_delay / 1000;
}

void loop()
{
  delay(delayMS);
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  Serial.print("Temperature: ");
  Serial.println(event.temperature);
  dht.humidity().getEvent(&event);
  Serial.print("Humidity: ");
  Serial.println(event.relative_humidity);
}
