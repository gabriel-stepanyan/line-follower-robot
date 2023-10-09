void readSensorInput()
{
  //sensors from left to right
  sensors[0] = digitalRead(SENSOR1);
  sensors[1] = digitalRead(SENSOR2);
  sensors[2] = digitalRead(SENSOR3);
  sensors[3] = digitalRead(SENSOR4);
}

void calculateError()
{
  if (sensors[0] == 0 && sensors[1] == 0 && sensors[2] == 0 && sensors[3] == 1)
  {
    error = 2; // 0 0 0 1
  } 
  else if (sensors[0] == 0 && sensors[1] == 0 && sensors[2] == 1 && sensors[3] == 1)
  {
    error = 1; // 0 0 1 1
  }
  else if (sensors[0] == 0 && sensors[1] == 1 && sensors[2] == 1 && sensors[3] == 0)
  {
    error = 0;  // 0 1 1 0
  }
  else if (sensors[0] == 1 && sensors[1] == 1 && sensors[2] == 0 && sensors[3] == 0) 
  {
    error = -1; // 1 1 0 0
  }
  else if (sensors[0] == 1 && sensors[1] == 0 && sensors[2] == 0 && sensors[3] == 0) 
  {
    error = -2; // 1 0 0 0
  }
  else if (sensors[0] == 1 && sensors[1] == 1 && sensors[2] == 1 && sensors[3] == 1) 
  {
    status = END; // 1 1 1 1
  }
}