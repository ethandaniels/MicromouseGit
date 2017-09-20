/*
  Ethan Daniels || Micromouse 2015-2016 || Phobos 1 || Base Maze Solving Algorithm
  Last Edited 1.17.2015 11:15PM  
  
  Uses if statements to find the best movements for the micromouse based on current position.
  This is the core maze solving algorithm.
*/

//basic wall and maze avoidance
void nav()
{
  //Default state of robot. Move forward when there is no wall straight ahead
  if (centerSensor(100) >= 10)
  {
    motorsForward();
  }
  
  //Turn right first if the center path is blocked
  if (centerSensor(100) <= 10 && leftSensor(100) >= 10 && rightSensor(100) >= 10) 
  {
    motorsRight();
  }
  
  //Turn left if there is an opening
  if (centerSensor(100) <= 10 && leftSensor(100) >= 10 && rightSensor(100) <= 10) 
  {
    motorsLeft();
  }
  
  //Turn Right if there is an opening
  if (centerSensor(100) <= 10 && rightSensor(100) >= 10 && leftSensor(100) <= 10) 
  {
    motorsRight();
  }
  
  //If a dead end is present 
  if (centerSensor(100) <= 10 && rightSensor(100) <= 10 && leftSensor(100) <= 10) 
  {
    motorsStop();
  } 
}

//defines the travel to the next NORTH cell, dependant on surroudings
void navNorth()
{
  switch(globalHeading)
  {
    //the robot is facing north
    case 1:
    {
      switch(sensorState)
      {
        case 1:
        {
          //move forward one cell
    
          //increase the acutal positon value
          posy = posy+1;
          break;
        }
        case 2:
        {
          //
          break;
        }
        case 3:
        {
           break;
        }
        case 4:
        {
           break;
        }
        case 5:
        {
           break;
        }
        case 6:
        {
          break;
        }
      }
    }
    
    //the robot is facing east
    case 2:
    {
      break;
    }
    
    //the robot is facing south
    case 4:
    {
      break;
    }
    
    //the robot is facing west
    case 8:
    {
      break;
    }
  }
  

  //mark the current cell as visited
  maze[posx][posy] = maze[posx][posy]+visited;

  //should NOT be here, must go into case values
  //increase the travel direction
  //posy = posy+1;
}

//defines the travel to the next EAST cell, dependant on surroudings
void navEast()
{

  //mark the current cell as visited
  maze[posx][posy] = maze[posx][posy]+visited;

  //should NOT be here, must go into case values
  //increase the travel direction
  //posx = posx+1;
}

//defines the travel to the next SOUTH cell, dependant on surroudings
void navSouth()
{

  //mark the current cell as visited
  maze[posx][posy] = maze[posx][posy]+visited;

  //should NOT be here, must go into case values
  //increase the travel direction
  //posy = posy-1;
}

//defines the travel to the next WEST cell, dependant on surroudings
void navWest()
{

  //mark the current cell as visited
  maze[posx][posy] = maze[posx][posy]+visited;

  //should NOT be here, must go into case values
  //increase the travel direction
  //posx = posx-1;
}

//will tell the robot the next position to navigate to
void nav2Neighbor()
{
//  int nextx;
//  int nexty;
//  getNeighbors(&nextx, &nexty);

  //create north neighbor
  int northx = posx;
  int northy = posy+1;

  //create east neighbor
  int eastx = posx+1;
  int easty = posy;
  
  //create south neighbor
  int southx = posx;
  int southy = posy-1;

  //create west neighbor
  int westx = posx-1;
  int westy = posy;

  //if the best neighbor is NORTH
  if(maze[northx][northy] < (maze[southx][southy] || maze[eastx][easty] || maze[westx][westy]))
  {
    navNorth();
  }
  
  //if th best neighbor is EAST
  if(maze[eastx][easty] < maze[northx][northy] || (maze[southx][southy] || maze[westx][westy]))
  {
    navEast();
  }
  
  //if the best neighbor is SOUTH
  if((maze[southx][southy] < maze[northx][northy] || maze[eastx][easty] || maze[westx][westy]))
  {
    navSouth();
  }
  
  //if the best neighbor is WEST
  if((maze[westx][westy] < maze[northx][northy] || maze[eastx][easty] || maze[southx][southy]))
  {
    navWest();
  }
  
}


