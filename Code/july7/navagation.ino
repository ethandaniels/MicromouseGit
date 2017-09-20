/*
  Ethan T. Daniels || Micromouse 2017-2018
   Last Edited 7.5.2017 7:44PM
  
  Creates two main functions for finding the center of the maze
  Creates movement profiles based on the global heading
  
  The directional based navigation is a little crazy. Though it depends what cell is desired next and will attemt to get
  to that cell in the most efficent manner.

  Example, im facing east but the best cell is south, but there is a wall only to my left, instaed of going straight i will go right
*/

//nav2Center, will attemt to navigate twoard the center of the maze, checking the distnace from center of each neighbor
void nav2Center()
{
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

  int nNeighbor = dist2Goal(northx, northy);
  int eNeighbor = dist2Goal(eastx, easty);
  int sNeighbor = dist2Goal(southx, southy);
  int wNeighbor = dist2Goal(westx, westy);

  if(nNeighbor < (eNeighbor && sNeighbor && wNeighbor))
  {
    navNorth();
  }
  if(eNeighbor < (nNeighbor && sNeighbor && wNeighbor))
  {
    navEast();
  }
  if(sNeighbor < (nNeighbor && eNeighbor && wNeighbor))
  {
    navSouth();
  }
  if(wNeighbor < (nNeighbor && eNeighbor && sNeighbor))
  {
    navWest();
  }
}


//cell ranking, will tell the robot best cell to go to next (RUN AFTER MAZE IS KNOWN)
void nav2Neighbor()
{
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
  if(maze[northx][northy] < (maze[southx][southy] && maze[eastx][easty] && maze[westx][westy]))
  {
    navNorth();
  }
  
  //if th best neighbor is EAST
  if(maze[eastx][easty] < maze[northx][northy] && (maze[southx][southy] && maze[westx][westy]))
  {
    navEast();
  }
  
  //if the best neighbor is SOUTH
  if((maze[southx][southy] < maze[northx][northy] && maze[eastx][easty] && maze[westx][westy]))
  {
    navSouth();
  }
  
  //if the best neighbor is WEST
  if((maze[westx][westy] < maze[northx][northy] && maze[eastx][easty] && maze[southx][southy]))
  {
    navWest();
  }
}

//defines the travel to the next NORTH cell, dependant on surroudings and global heading
void navNorth()
{
  //add self correction at somepoint
  switch(globalHeading)
  {
    //the robot is facing north || desire north
    case 1:
    {
      if(sensorState == (1 || 5 || 6))//desired condition satisfied
      {
        //move forward one cell
        fwdOneSquare();
        
        //increase the acutal positon value
        posy = posy+1;
      }
      if(sensorState == 2)
      {
        rightOneSquare();
        globalHeading = 2;
        posx = posx+1;
      }
      if(sensorState == 3)
      {
        leftOneSquare();
        globalHeading = 8;
        posx = posx-1;
      }
      if(sensorState == 4)
      {
        turnAround2Fwd();
        globalHeading = 4;
        posy = posy-1;
      }
    }
    //the robot is facing east || desire north
    case 2:
    {
      if(sensorState == (1 || 5))
      {
        fwdOneSquare();
        posx = posx+1;
      }
      if(sensorState == (3 || 6))//desired condition satisfied
      {
        leftOneSquare();
        globalHeading = 1;
        posy = posy+1;
      }
      if(sensorState == 2)
      {
        rightOneSquare();
        globalHeading = 4;
        posy = posy-1;
      }
      if(sensorState == 4)
      {
        turnAround2Fwd();
        globalHeading = 8;
        posx = posx-1;
      }
    }
    //the robot is facing south || desire north
    case 4:
    {
      if(sensorState == (1 || 2 || 3 || 4 || 5 || 6))//desired condition satisfied
      {
        turnAround2Fwd();
        globalHeading = 1;
        posy = posy+1;
      }
    }
    //the robot is facing west || desire north
    case 8:
    {
      if(sensorState == (2 || 5))//desired condition satisfied
      {
        rightOneSquare();
        globalHeading = 1;
        posy = posy+1;
      }
      if(sensorState == (1 || 6))
      {
        fwdOneSquare();
        posx = posx-1;
      }
      if(sensorState == 3)
      {
        leftOneSquare();
        globalHeading = 4;
        posy = posy-1;
      }
      if(sensorState == 4)
      {
        turnAround2Fwd();
        globalHeading = 2;
        posx = posx-1;
      }
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void navEast()
{
  switch(globalHeading)
  {
    //facing north || desired east
    case 1:
    {
       if(sensorState == (1 || 6))
       {
        fwdOneSquare();
        posy = posy+1;
        //no need to update globalHeading, still facing north
       }
       if(sensorState == (2 || 5))//desired condition satisfied
       {
        rightOneSquare();
        globalHeading = 2;
        posx = posx+1;
       }
       if(sensorState == 4)
       {
        turnAround2Fwd();
        globalHeading = 4;
        posy = posy-1;
       }
       if(sensorState == 3)
       {
        leftOneSquare();
        globalHeading = 4;
        posx = posx-1;
       }
    }
    //facing east || desire east
    case 2:
    {
      if(sensorState == (1 || 5 || 6))//desired condition satisfied
      {
        fwdOneSquare();
        posx = posx+1;
        //global heading still east, no need to update
      }
      if(sensorState == 2)
      {
        rightOneSquare();
        globalHeading = 4;
        posy = posy-1;
      }
      if(sensorState == 3)
      {
        leftOneSquare();
        globalHeading = 1;
        posy = posy+1;
      }
      if(sensorState == 4)
      {
        turnAround2Fwd();
        globalHeading = 8;
        posx = posx-1;
      }
    }
    //facing south || desired east
    case 4: 
    {
      if(sensorState == (3 || 6))//desired condition satisfied
      {
        leftOneSquare();
        globalHeading = 2;
        posx = posx+1;
      }
      if(sensorState == (1 || 5))
      {
        fwdOneSquare();
        posy = posy-1;
      }
      if(sensorState == 4)
      {
        turnAround2Fwd();
        globalHeading = 1;
        posy = posy+1;
      }
      if(sensorState == 2)
      {
        rightOneSquare();
        globalHeading = 8;
        posx = posx-1;
      }
    }
    //facing west || desired east
    case 8:
    {
      if(sensorState == (1 || 2 || 3 || 4 || 5 || 6))
      {
        turnAround2Fwd();
        globalHeading = 1;
        posx = posx-1;
      }
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void navSouth()
{
  switch(globalHeading)
  {
    //facing north || desired south
    case 1:
    {
      if(sensorState == (1 || 2 || 3 || 4 || 5 || 6))
      {
        turnAround2Fwd();
        globalHeading = 4;
        posy = posy-1;
      }
    }
    //facing east || desired south
    case 2:
    {
      if(sensorState == (2 || 5))//desired condition satisfied
      {
        rightOneSquare();
        globalHeading = 4;
        posy = posy-1;
      }
      if(sensorState == (1 || 6))
      {
        fwdOneSquare();
        posx = posx+1;
      }
      if(sensorState == 4)
      {
        turnAround2Fwd();
        globalHeading = 8;
        posx = posx-1;
      }
      if(sensorState == 3)
      {
        leftOneSquare();
        globalHeading = 1;
        posy = posy+1;
      }
    }
    //facing south || desired south
    case 4:
    {
      if(sensorState == (1 || 5 || 6))//desired condition satisfied 
      {
        fwdOneSquare();
        posy = posy-1;
      }
      if(sensorState == 2)
      {
        rightOneSquare();
        globalHeading = 8;
        posx = posx-1;
      }
      if(sensorState == 3)
      {
        leftOneSquare();
        globalHeading = 2;
        posx = posx+1;
      }
      if(sensorState == 4)
      {
        turnAround2Fwd();
        globalHeading = 1;
        posy = posy+1;
      }
    }
    //facing west || desired south
    case 8:
    {
      if(sensorState == (3 || 6))//desired conditon satisfied
      {
        leftOneSquare();
        globalHeading = 4;
        posy = posy-1;
      }
      if(sensorState == (1 || 5))
      {
        fwdOneSquare();
        posx = posx+1;
      }
      if(sensorState == 2)
      {
        rightOneSquare();
        globalHeading = 1;
        posy = posy+1;
      }
      if(sensorState ==  4)
      {
        turnAround2Fwd();
        globalHeading = 2;
        posx = posx+1;
      }
    }
  }
}
void navWest()
{
  switch(globalHeading)
  {
    //facing north || desired west
    case 1:
    {
      if(sensorState == (3 || 6))//desired  condition satisfied
      {
        leftOneSquare();
        globalHeading = 8;
        posx = posx-1;
      }
      if(sensorState == (1 || 5))
      {
        fwdOneSquare();
        posy = posy+1;
      }
      if(sensorState == (2 || 4))
      {
        turnAround2Fwd();
        globalHeading = 4;
        posy = posy-1;
      }
    }
    //facing east || desired west
    case 2:
    {
      if(sensorState == (1 || 2 || 3 || 4 || 5 || 6))
      {
        turnAround2Fwd();
        globalHeading = 8;
        posx = posx-1;
      }
    }
    //facing south || desired west
    case 4:
    {
      if(sensorState == (2 || 5))//desired condition satisfied
      {
        rightOneSquare();
        globalHeading = 8;
        posx = posx-1;
      }
      if(sensorState == (1 || 6))
      {
        fwdOneSquare();
        posy = posy-1;
      }
      if(sensorState == 3)
      {
        leftOneSquare();
        globalHeading = 2;
        posx = posx-1;
      }
      if(sensorState == 4)
      {
        turnAround2Fwd();
        globalHeading == 1;
        posy = posy+1;
      }
    }
    //facing west || desired west
    case 8:
    {
      if(sensorState == (1 || 5 || 6))//desired condition satisfied
      {
        fwdOneSquare();
        posx = posx-1;
      }
      if(sensorState == 2)
      {
        rightOneSquare();
        globalHeading = 1;
        posy = posy+1;
      }
      if(sensorState == 3)
      {
        leftOneSquare();
        globalHeading = 4;
        posy = posy-1;
      }
      if(sensorState == 4)
      {
        turnAround2Fwd();
        globalHeading = 2;
        posx = posx-1;
      }
    }
  }
}

