//Ethan T. daniels
//This code creates speed varaince control for use with two DC motors and an L293D IC
//For use with ETD RevB Board

//define the PWN enable pins for motors
#define ML 10
#define MR 11

//define the control pins for motors
#define ML1 5
#define ML2 6
#define MR1 12
#define MR2 13

void setup() {
  //setting up the motor enable and control pins as outputs
  pinMode(ML, OUTPUT);
  pinMode(MR, OUTPUT);
  pinMode(ML1, OUTPUT);
  pinMode(ML2, OUTPUT);
  pinMode(MR1, OUTPUT);
  pinMode(MR2, OUTPUT);

}

void slowForward(){
  analogWrite(ML,63);
  analogWrite(MR,63); 
  
  digitalWrite(ML1, HIGH);
  digitalWrite(ML2, LOW);
  digitalWrite(MR1, HIGH);
  digitalWrite(MR2, LOW);

}
void medForward(){
  analogWrite(ML,127);
  analogWrite(MR,127); 
  
  digitalWrite(ML1, HIGH);
  digitalWrite(ML2, LOW);
  digitalWrite(MR1, HIGH);
  digitalWrite(MR2, LOW);
}
void fullForward(){
  analogWrite(ML,255);
  analogWrite(MR,255); 
  
  digitalWrite(ML1, HIGH);
  digitalWrite(ML2, LOW);
  digitalWrite(MR1, HIGH);
  digitalWrite(MR2, LOW);
}

void loop(){
  
}
