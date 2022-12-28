//A full description of this module (and many others) can be downloaded at: https://eve_arduino

#include "MPU6050_6Axis_MotionApps20.h"

MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;


void setup()
{
    Serial.begin(9600);
    delay(5000);
    Serial.println("Initializing I2C devices...");
    accelgyro.initialize();
    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
}

void loop()
{
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
        Serial.print(ax); Serial.print("\t");
        Serial.print(ay); Serial.print("\t");
        Serial.print(az); Serial.print("\t");
        Serial.print(gx); Serial.print("\t");
        Serial.print(gy); Serial.print("\t");
        Serial.print(gz);
        Serial.println();
}
