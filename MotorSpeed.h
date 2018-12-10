

#ifndef MotorSpeed_h
#define MotorSpeed_h

#include "Arduino.h"
#include <Wire.h>




class Motor {
  public:
    Motor();

    int getSpeed();

    void setSpeed(int x);

  private:
    int speed;
};




#endif
