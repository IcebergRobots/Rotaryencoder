#include "Utilities.h"

void refreshMotor() {
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