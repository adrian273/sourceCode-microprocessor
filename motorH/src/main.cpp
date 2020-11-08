/**
 * Adrian Verdugo ( アドリアン )
 * @github adrian273
 * @since 11/8/2020
 * 
 * */

#include <Arduino.h>
#include <AccelStepper.h>
#define HALFSTEP 8

#define motorPin8 8  // IN1 on the ULN2003 driver
#define motorPin9 9  // IN2 on the ULN2003 driver
#define motorPin10 10 // IN3 on the ULN2003 driver
#define motorPin11 11 // IN4 on the ULN2003 driver

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper stepper(HALFSTEP, motorPin8, motorPin10, motorPin9, motorPin11);

void setup()
{
  Serial.begin(9600);
  stepper.setMaxSpeed(200.0);
  stepper.setAcceleration(100.0);
}

void loop()
{
  if (Serial.available())
  {
    String response = Serial.readString();
    if (response != "0")
    {
      stepper.runToNewPosition(response.toInt());
    }
  }
}