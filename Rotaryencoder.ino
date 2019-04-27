//#include <math.h>
#include <Wire.h>
#include "RotaryEncoder.h"

RotaryEncoder encoder(5, 10);
RotaryEncoder encoder2(6, 11);

int pos = 0;
unsigned long tLast = 0;
unsigned long tLast2 = 0;
float geschwindigkeit = 0;
float geschwindigkeit2 = 0;
int speed = 0;
int speed2 = 0;


void setup()
{
  //================================================WICHTIG==============================================
  //Adresse 8 für den atmega vorne(Encoder 0 und 3)
  //Adresse 9 für den atmega hinten(Encoder 1 und 2)
  //================================================WICHTIG==============================================
  Wire.begin(7);
  Wire.onRequest(requestEvent);
  //Serial.begin(57600);
  //Serial.println("SimplePollRotator example for the RotaryEncoder library.");
}


void loop() {
  encoder.tick();
  if (encoder.getPosition() != 0 || micros() - tLast > 50000) {
    geschwindigkeit = (((float)encoder.getPosition() * 400000) / (long)(micros() - tLast));
    //speed = map((constrain(geschwindigkeit, -1023 , 1023)), -1023 , 1023 , -128 , 127 );
    speed = (constrain(map(geschwindigkeit, -100, 100, -25, 25), -127, 127)) + 127;
    tLast = micros();
    encoder.setPosition(0);
    //Serial.println(speed);
  }
  encoder2.tick();
  if (encoder2.getPosition() != 0 || micros() - tLast2 > 50000) {
    geschwindigkeit2 = (((float)encoder2.getPosition() * 400000) / (long)(micros() - tLast2));
    speed2 = (constrain(map(geschwindigkeit2, -100, 100, -25, 25), -127, 127)) + 127;
    tLast2 = micros();
    encoder2.setPosition(0);
    //Serial.println(speed2);
  }
}

void requestEvent() {
  byte data[2];
  data[0] = speed;
  data[1] = speed2;
  Wire.write(data, 2);
  //Serial.println(String(speed) + " " + String(speed2));
  //Wire.write(42);
} 


