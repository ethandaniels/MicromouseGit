#include <Encoder.h>

//declaring motors
const int leftA = 11;
const int leftB = 10;
const int rightA = 13;
const int rightB = 12;
int motorState = 0;

//declaring sensors
const int irLeftSensor = 0;
const int irCenterSensor = 1;
const int irRightSensor = 2;

//declaring encoder pins (digital pins)
Encoder leftEnc(0,1);
Encoder rightEnc(20,21);
  
void setup()
{
  //motors
  pinMode(leftA, OUTPUT);
  pinMode(leftB, OUTPUT);
  pinMode(rightA, OUTPUT);
  pinMode(rightB, OUTPUT);
  motorsStop();
  
  //setup
  Serial.begin(9600);
}

void loop()
{
  long leftPos = leftEnc.read();
  long rightPos = rightEnc.read();
  //Forward
  motorsForward();
  delay(500);
  Serial.println("Left Encoder: "+leftPos);
  Serial.println("Right Encoder: "+rightPos);
  
  motorsStop();
  delay(500);
  
  //Left
  motorsLeft();
  delay(500);
  
  motorsStop();
  delay(500);
  
  //Right
  motorsRight();
  delay(500);
  
  motorsStop();
  delay(500);
  
  //Displaying the sensor values to the serial monitor
  Serial.print("Center Distance = ");
  Serial.println(centerSensor(100));
  Serial.print("Left Distance = ");
  Serial.println(leftSensor(100));
  Serial.print("Right Distance = ");
  Serial.println(rightSensor(100));
  delay(2000);
}
  
