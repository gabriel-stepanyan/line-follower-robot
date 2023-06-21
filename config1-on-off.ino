/*
0 ÷ 255 for motor speeds
0 - low speed, 255 - high speed

IR sensors:
over black: 1
over white: 0

motor functions:
moving forward: both sensors are over a white surface - both 0
turning left: left sensor is on the black line - right 0, left 1
turning right: right sensor is on the black line - right 1, left 0
stopping: both sensors are on the black line - both 1
*/

//motor set A connections
const int enA = 10;
const int in1 = 9;
const int in2 = 8;

//motor set B connections
const int enB = 5;
const int in3 = 7;
const int in4 = 6;

int motorSpeed = 80;
int rotationSpeed = 160;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //sensors - input
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop() {
  int LS = digitalRead(A0); //left sensor
  int RS = digitalRead(A1); //right sensor

  if (RS == 0 && LS == 0) {
    forward();  //go forward
  } else if (RS == 1 && LS == 0) {
    right();  //move right
  } else if (RS == 0 && LS == 1) {
    left();  //move left
  } else {
    stop();  //stop
  }

  delay(10);
}

void forward() {
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

void right() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enA, rotationSpeed);
  analogWrite(enB, rotationSpeed);
}

void left() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  analogWrite(enA, rotationSpeed);
  analogWrite(enB, rotationSpeed);
}

void stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
