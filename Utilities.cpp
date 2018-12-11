#include "Utilities.h"

void refreshMotor() {
  Wire.requestFrom(8, 2);
  if (Wire.available()) {                           //Encoder 0 + 1
    motor0.setSpeed(Wire.read() - 127);     //hinten links
    motor1.setSpeed(Wire.read() - 127);     //vorne links
  }

  Wire.requestFrom(9, 2);
  if (Wire.available()) {                           //Encoder 2 + 3
    motor2.setSpeed(Wire.read() - 127);     //hinten rechts
    motor3.setSpeed(Wire.read() - 127);     //vorne rechts
  }
}
