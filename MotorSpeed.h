#ifndef MotorSpeed_h
#define MotorSpeed_h

#include "core.h"

class Motor {
  public:
    Motor();

    int getSpeed();

    void setSpeed(int x);

  private:
    int speed;
};

extern Motor motor1;
extern Motor motor2;
extern Motor motor3;
extern Motor motor4;

#endif
