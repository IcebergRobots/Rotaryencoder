#include "MotorSpeed.h"

Motor::Motor() {
  speed = 0;
}

int Motor::getSpeed() {
  return speed;
}

void Motor::setSpeed(int x){
  speed = x;
}

Motor motor1 = Motor();
Motor motor2 = Motor();
Motor motor3 = Motor();
Motor motor4 = Motor();