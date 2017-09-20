/*
  Ethan Daniels || Micromouse 2015-2016 || Phobos 1 || Base Maze Solving Algorithm
  Last Edited 1.17.2015 11:15PM  
  
  Uses if statements to find the best movements for the micromouse based on current position.
  This is the core maze solving algorithm.
*/
void movement()
{
  //Default state of robot. Move forward when there is no wall straight ahead
  if (centerSensorAvgValue(100) >= 10)
  {
    motorsForward();
  }
  
  //Turn right first if the center path is blocked
  if (centerSensorAvgValue(100) <= 10 && leftSensorAvgValue(100) >= 10 && rightSensorAvgValue(100) >= 10) 
  {
    motorsRight();
  }
  
  //Turn left if there is an opening
  if (centerSensorAvgValue(100) <= 10 && leftSensorAvgValue(100) >= 10 && rightSensorAvgValue(100) <= 10) 
  {
    motorsLeft();
  }
  
  //Turn Right if there is an opening
  if (centerSensorAvgValue(100) <= 10 && rightSensorAvgValue(100) >= 10 && leftSensorAvgValue(100) <= 10) 
  {
    motorsRight();
  }
  
  //If a dead end is present 
  if (centerSensorAvgValue(100) <= 10 && rightSensorAvgValue(100) <= 10 && leftSensorAvgValue(100) <= 10) 
  {
    motorsStop();
  } 
}
