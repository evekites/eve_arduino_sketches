#include <Braccio.h>
#include <Servo.h>

Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;


void setup() {  
  Braccio.begin();
  Serial.begin(9600);
}

void loop() {

  Serial.println("Straight up, hand open");
  Braccio.ServoMovement(20, 100,  85,  90,  95,  180,  15);

  Serial.println("Rotate to the right");
  Braccio.ServoMovement(20, 180,  85,  90,  95,  80,  15); 

  Serial.println("Bent over");
  Braccio.ServoMovement(20, 180,  45,  50,   0,  80,  15);

  Serial.println("Wait 1 second before grabbing object");
  delay(1000);  
  Braccio.ServoMovement(20, 180,  45,  50,   0,  80,  60); 

  Serial.println("Straight up, hand closed");
  Braccio.ServoMovement(20, 100,  85,  90,  95,  180,  60); 

  Serial.println("Rotate to the left");
  Braccio.ServoMovement(20, 0,  85,  90,  95,  80,  60); 

  Serial.println("Bent over");
  Braccio.ServoMovement(20, 0,  45,  50,   0,  80,  60); 

  Serial.println("Drop object");
  Braccio.ServoMovement(20, 0,  45,  50,   0,  80,  15); 

  Serial.println("Straight up, hand open");
  Braccio.ServoMovement(20, 100,  85,  90,  95,  180,  15); 

  Serial.println("Bent over");
  Braccio.ServoMovement(20, 100,  75,  10,   10,  100,  15); 

  Serial.println("Wait 1 second before grabbing object");
  delay(1000);  
  Braccio.ServoMovement(20, 100,  75,  10,   10,  100,  60); 

  Serial.println("Straight, up hand closed");
  Braccio.ServoMovement(20, 100,  85,  90,  95,  180,  60); 

  Serial.println("Rotate to the right");
  Braccio.ServoMovement(20, 180,  85,  90,  95,  80,  60);  

  Serial.println("Bent over");
  Braccio.ServoMovement(20, 180,  45,  50,   0,  80,  60); 

  Serial.println("Drop object");
  Braccio.ServoMovement(20, 180,  45,  50,   0,  80,  15); 
  
  Serial.println("Straight up, hand open");
  Braccio.ServoMovement(20, 100,  85,  90,  95,  180,  15); 

  Serial.println("Rotate to the left");
  Braccio.ServoMovement(20, 0,  85,  90,  95,  80,  15); 

  Serial.println("Bent over");
  Braccio.ServoMovement(20, 0,  45,  50,   0,  80,  15); 

  Serial.println("Wait 1 second before grabbing object");
  delay(1000);  
  Braccio.ServoMovement(20, 0,  45,  50,   0,  80,  60); 

  Serial.println("Straight up, hand closed");
  Braccio.ServoMovement(20, 100,  85,  90,  95,  180,  60); 

  Serial.println("Bent over");
  Braccio.ServoMovement(20, 100,  75,  10,   10,  100,  60); 

  Serial.println("Drop object");
  Braccio.ServoMovement(20, 100,  75,  10,   10,  100,  15); 

}
