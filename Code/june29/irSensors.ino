/*
  Ethan Daniels || Micromouse 2015-2016 || Phobos 1 || IR Sensors
  Last Edited 1.17.2015 10:16PM  

  Creates sensor states
  Creates 3 functions to find a number of avg values of the ir sensor and converts value to cm
*/
//Center Sensor
int centerSensor(int count) 
{
  int sum = 0;
  for (int i = 0; i < count; i++)
  {
    int sensorValue = analogRead(irCenterSensor); //read the ir sensor value
    int distance_cm = pow(3027.4 / sensorValue, 1.2134); //converting readings to distance in cm. comes from ir data sheet
    sum = sum + distance_cm;
  }
  return (sum / count);
}

//Left Sensor
int leftSensor(int count) 
{
  int sum = 0;
  for (int i = 0; i < count; i++)
  {
    int sensorValue = analogRead(irLeftSensor);
    int distance_cm = pow(3027.4 / sensorValue, 1.2134);
    sum = sum + distance_cm;
  }
  return (sum / count);
}

//Right Sensor
int rightSensor(int count) 
{
  int sum = 0;
  for (int i = 0; i < count; i++)
  {
    int sensorValue = analogRead(irRightSensor);
    int distance_cm = pow(3027.4 / sensorValue, 1.2134);
    sum = sum + distance_cm;
  }
  return (sum / count);
}

int sensorState = 0;

//Creating Sensor States
int getSensorState()
{
  //example framework
  if(centerSensor(100) < 10 && (leftSensor(100) < 5 && rightSensor(100) < 5))
  {
    sensorState = 1;

    //also add to the wall byte
    //example
    //maze[posx][posy] = maze[posx][posy]+east+west;
  }
  
}


