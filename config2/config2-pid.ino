/*
0 ÷ 255 for motor speeds
0 - low speed, 255 - high speed

IR sensors:
over black: 1
over white: 0
*/

#include "defines.h"

void setup() 
{
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(SENSOR1, INPUT);
  pinMode(SENSOR2, INPUT);
  pinMode(SENSOR3, INPUT);
  pinMode(SENSOR4, INPUT);
}

void loop() 
{
  readSensorInput();

  calculateError();
   
  if (status != END)
  {
    calculatePID();
    setSpeed();

    if (error > 0 && error <= 2)
    {
      right();
    }
    else if (error == 0)
    {
      forward();
    }
    else if (error >= -2)
    {
      left();
    }
  }
  else 
  {
    stop();  
    prevError = error;
  }
}

void calculatePID()
{
  pValue = error;
  iValue += error;
  dValue = error - prevError;
  pidValue = (Kp * pValue) + (Ki * iValue) + (Kd * dValue);
  prevError = error;
}