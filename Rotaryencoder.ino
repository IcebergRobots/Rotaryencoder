#include "core.h"
  
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