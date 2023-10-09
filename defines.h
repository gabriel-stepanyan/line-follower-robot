//helpers
#define END 0
int status = 1;

//motor set A connections
#define ENA 6
#define IN1 10
#define IN2 9

//motor set B connections
#define ENB 5
#define IN3 8 
#define IN4 7 

//sensor module connections - from left to right
#define SENSOR1 A0
#define SENSOR2 A1
#define SENSOR3 A2
#define SENSOR4 A3

int sensors[4] = {0, 0, 0, 0};

//speed
const int INITIAL_MOTOR_SPEED = 85;

//PID
float Kp = 29; 
float Ki = 0.000001;
float Kd = 17;

float error = 0;
float prevError = 0;

float pValue = 0; 
float iValue = 0;
float dValue = 0;
float pidValue = 0;
