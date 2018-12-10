

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
