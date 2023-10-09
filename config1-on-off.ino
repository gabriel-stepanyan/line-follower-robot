/*
0 ÷ 255 for motor speeds
0 - low speed, 255 - high speed

IR sensors:
over black: 1
over white: 0

motor functions:
moving forward: sensors 1 & 4 are over a white surface
turning left: sensors 1 & 2 are over the black line
turning right: sensors 3 & 4 are over the black line
stopping: all sensors are over the black line
*/

//motor set A connections
const int enA = 6;
const int in1 = 10;
const int in2 = 9;

//motor set B connections
const int enB = 5;
const int in3 = 8;
const int in4 = 7;

const int motorSpeed = 80;
const int rotationSpeed = 120;

void setup() 
{
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //sensors - input
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
}

void loop() 
{
  //sensors from left to right
  const int S1 = digitalRead(A0); 
  const int S2 = digitalRead(A1);
  const int S3 = digitalRead(A2);
  const int S4 = digitalRead(A3);
  
  if (S1 == 0 && S2 == 1 && S3 == 1 && S4 == 0)
  {
    forward();  //go forward
  } 
  else if (S1 == 0 && S2 == 0 && S3 == 0 && S4 == 1)
  {
    right();  //move right
  }
  else if (S1 == 1 && S2 == 0 && S3 == 0 && S4 == 0)
  {
    left();  //move left
  }
  else if (S1 == 1 && S2 == 1 && S3 == 1 && S4 == 1) 
  {
    stop();  //stop
  }
}

void forward() 
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enA, motorSpeed);
  analogWrite(enB, motorSpeed);
}

/*
void backward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  analogWrite(enA, 80);
  analogWrite(enB, 80);
}*/

void right() 
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enA, rotationSpeed);
  analogWrite(enB, rotationSpeed);
}

void left() 
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  analogWrite(enA, rotationSpeed);
  analogWrite(enB, rotationSpeed);
}

void stop() 
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}