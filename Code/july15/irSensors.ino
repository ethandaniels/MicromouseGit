/*
  Ethan Daniels || Micromouse 2015-2016 || Phobos 1 || IR Sensors
  Last Edited 1.17.2015 10:16PM  

  Creates sensor states
  Creates 3 functions to find a number of avg values of the ir sensor and converts value to cm
*/
//create sensor state variable
int sensorState = 0;

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

//Left Sensor [SEES RIGHT WALL]
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

//Right Sensor [SEES LEFT WALL]
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

//Creating Sensor States
int getSensorState()
{
  //DISTANCE VALUES WILL CHANGE AFTER TESTING
  
  //state 1, walls right and left
  if(centerSensor(100) > 10 && (leftSensor(100) < 5 && rightSensor(100) < 5))
  {
    sensorState = 1;

    //if this cell has been visited, dont add any wall information
    if(maze[posx][posy] > 16)
    {
      maze[posx][posy] = maze[posx][posy];
    }
    //if the cell hasn't been visited add wall information and visisted bit
    else
    {
      maze[posx][posy] = maze[posx][posy]+east+west+visited;
    }
  }
  
  //state 2, walls forward and left
  if(leftSensor(100) > 10 && (centerSensor(100) < 5 && rightSensor(100) < 5))
  {
    sensorState = 2;
    //if this cell has been visited, dont add any wall information
    if(maze[posx][posy] > 16)
    {
      maze[posx][posy] = maze[posx][posy];
    }
    //if the cell hasn't been visited add wall information and visisted bit
    else
    {
      maze[posx][posy] = maze[posx][posy]+north+west+visited;
    }
  }
  
  //state 3, walls forward and right
  if(rightSensor(100) > 10 && (centerSensor(100) < 5 && leftSensor(100) <5))
  {
    sensorState = 3;
    
    //if this cell has been visited, dont add any wall information
    if(maze[posx][posy] > 16)
    {
      maze[posx][posy] = maze[posx][posy];
    }
    //if the cell hasn't been visited add wall information and visisted bit
    else
    {
      maze[posx][posy] = maze[posx][posy]+north+east+visited;
    }
  }
  
  //sate 4, walls forward, right, and left
  if(rightSensor(100) < 5 && leftSensor(100) < 5 && centerSensor(100) <5)
  {
    sensorState = 4; 
    //if this cell has been visited, dont add any wall information
    if(maze[posx][posy] > 16)
    {
      maze[posx][posy] = maze[posx][posy];
    }
    //if the cell hasn't been visited add wall information and visisted bit
    else
    {
      maze[posx][posy] = maze[posx][posy]+north+east+west+visited;
    }
  }

  //state 5, wall to the left no wall ahead or to right
  if(rightSensor(100) < 5 && (centerSensor(100) > 10 && leftSensor(100) > 10))
  {
    sensorState = 5;
    //if this cell has been visited, dont add any wall information
    if(maze[posx][posy] > 16)
    {
      maze[posx][posy] = maze[posx][posy];
    }
    //if the cell hasn't been visited add wall information and visisted bit
    else
    {
      maze[posx][posy] = maze[posx][posy]+west+visited;
    }
  }

  //state 6, wall to the right no wall ahead or to left
  if(leftSensor(100) < 5 && (centerSensor(100) > 10 && leftSensor(100) > 10))
  {
    sensorState = 6;
    //if this cell has been visited, dont add any wall information
    if(maze[posx][posy] > 16)
    {
      maze[posx][posy] = maze[posx][posy];
    }
    //if the cell hasn't been visited add wall information and visisted bit
    else
    {
      maze[posx][posy] = maze[posx][posy]+east+visited;
    }
  }
}


