#include <Wire.h>
#include "MotorSpeed.h"

  extern Motor motor1;
  extern Motor motor2;
  extern Motor motor3;
  extern Motor motor4;
  
void setup(){
  Wire.begin();

}

void loop(){
  refreshMotor();
  Serial.println(motor1.getSpeed());
  Serial.println(motor2.getSpeed());
  Serial.println(motor3.getSpeed());
  Serial.println(motor4.getSpeed());
  
}


void refreshMotor(){
  Wire.requestFrom(8, 2);
  if (Wire.available()) {
    motor1.setSpeed(Wire.read() - 127);
    motor2.setSpeed(Wire.read() - 127);
  }

  Wire.requestFrom(9, 2);
  if (Wire.available()) {
    motor3.setSpeed(Wire.read() - 127);
    motor4.setSpeed(Wire.read() - 127);
  }
}
