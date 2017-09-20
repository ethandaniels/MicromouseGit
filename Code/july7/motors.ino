/*
  Ethan T. Daniels || Micromouse 2017-2018
  Last Edited 7.5.2017 7:44PM

  Creates basic motor control for the micromouse
  Built for use with the L293D H-Bridge and Faulhaber 1717 motors w/ 512 Encoders
*/

//will define movement w/ use of encoder
void fwdOneSquare()
{
  
}
void leftOneSquare()
{
  
}
void rightOneSquare()
{
  
}
//have to figure out in testing best movements
void turnAround2Fwd()
{
  
}


void motorsForward()     // Moves Robot forward
{
  leftForward();
  rightForward();
}
void motorsBackward()    // Moves Robot backwards
{
  leftBackward();
  rightBackward();
}
void motorsStop()        // Stops Robot
{
  leftStop();
  rightStop();
}
void motorsLeft()    // Turns Robot to the left
{
  leftBackward();
  rightForward();
}
void motorsRight()   // Turn Robot to the right
{
  rightBackward();
  leftForward();
}


//left
void leftForward()         // left motor to rotate ccw (forward)
{
  digitalWrite(leftA, HIGH);
  digitalWrite(leftB, LOW);
}
void leftBackward()        // left motor to rotate cw (backward)
{
  digitalWrite(leftA, LOW);
  digitalWrite(leftB, HIGH);
}

void leftStop()            // left motor does not rotate
{
  digitalWrite(leftA, LOW);
  digitalWrite(leftB, LOW);
}

//right
void rightForward()       // right motor to rotate cw (forward)
{
  digitalWrite(rightA, HIGH);
  digitalWrite(rightB, LOW);
}
void rightBackward()      // right motor to rotate ccw (backward)
{
  digitalWrite(rightA, LOW);
  digitalWrite(rightB, HIGH);
}

void rightStop()         // right motor does not rotate
{
  digitalWrite(rightA, LOW);
  digitalWrite(rightB, LOW);
}
