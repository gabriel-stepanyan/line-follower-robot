void setSpeed()
{
  int leftSetSpeed = INITIAL_MOTOR_SPEED - pidValue;
  int rightSetSpeed = INITIAL_MOTOR_SPEED + pidValue;
  
  leftSetSpeed = constrain(leftSetSpeed, 0, 255);
  rightSetSpeed = constrain(rightSetSpeed, 0, 255);

  analogWrite(ENA, leftSetSpeed);
  analogWrite(ENB, rightSetSpeed);
}

void forward() 
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void left()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stop() 
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}