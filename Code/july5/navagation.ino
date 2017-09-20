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
    //the robot is facing north
    case 1:
    {
      switch(sensorState)
      {
        case 1: //wall right and left
        {
          //move forward one cell
          fwdOneSquare();
          
          //increase the acutal positon value
          posy = posy+1;
        }
        case 2: //wall forward and left
        {
          //navigate to the cell next door
          rightOneSquare();

          //update global heading
          globalHeading = 2;

          //update positon in maze
          posx = posx+1;
        }
        case 3: //wall forward and right
        {
           //navigate to the left cell
           leftOneSquare();

           //update global heading
           globalHeading = 8;

           //update positon in maze
           posx = posx-1;
        }
        case 4: //dead end
        {
           //turn the mouse around and go back to previous cell
           turnAround2Fwd();
           getSensorState(); //updates walls and double checks sensors
                             //revert to best neighbor vale, relies on how many walls are surrounding neighbor cells
                             //this is best approach because now we know that dead end cell has walls
           nav2Neighbor(); //we are fucked if this returns a call to nav north.
           
           //will not update global heading in the hopes that nav2Neighbor resolves issue and bot goes to new cell 
        }
        case 5: //wall to left but none ahead or to right
        {
          //faster to keep going straight instaed of turning
          //move forward one cell
          fwdOneSquare();
          
          //increase the acutal positon value
          posy = posy+1;
        }
        case 6: //wall to right but none ahead or to left
        {
          //faster to keep going straight instaed of turning
          //move forward one cell
          fwdOneSquare();
          
          //increase the acutal positon value
          posy = posy+1;
        }
      }
    }
    
    //the robot is facing east
    case 2:
    {
      switch(sensorState)
      {
        case 1: //wall right and left
          {
            //move forward one cell
            fwdOneSquare();
            
            //increase the acutal positon value
            posx = posx+1;
          }
          case 2: //wall forward and left
          {
            //navigate to the cell next door
            rightOneSquare();
  
            //update global heading
            globalHeading = 4;
  
            //update positon in maze
            posy = posy-1;
          }
          case 3: //wall forward and right
          {
             //navigate to the left cell
             leftOneSquare();
  
             //update global heading
             globalHeading = 1;
  
             //update positon in maze
             posy = posy+1;
          }
          case 4: //dead end
          {
             //turn the mouse around and go back to previous cell
             turnAround2Fwd();
             getSensorState(); //updates walls and double checks sensors
                               //revert to best neighbor vale, relies on how many walls are surrounding neighbor cells
                               //this is best approach because now we know that dead end cell has walls
             nav2Neighbor(); //we are fucked if this returns a call to nav north.
             
             //will not update global heading in the hopes that nav2Neighbor resolves issue and bot goes to new cell 
          }
          case 5: //wall to left but none ahead or to right
          {
            //faster to keep going straight instaed of turning
            //move forward one cell
            fwdOneSquare();
            
            //increase the acutal positon value
            posx = posx+1;
          }
          case 6: //wall to right but none ahead or to left
          {
            //faster to keep going straight instaed of turning
            //move forward one cell
            fwdOneSquare();
            
            //increase the acutal positon value
            posx = posx+1;
          }
      }
    }
    
    //the robot is facing south
    case 4:
    {
      switch(sensorState)
      {
        case 1: //wall right and left
        {
          //move forward one cell
          fwdOneSquare();
          
          //increase the acutal positon value
          posy = posy-1;
        }
        case 2: //wall forward and left
        {
          //navigate to the cell next door
          rightOneSquare();

          //update global heading
          globalHeading = 8;

          //update positon in maze
          posx = posx-1;
        }
        case 3: //wall forward and right
        {
           //navigate to the left cell
           leftOneSquare();

           //update global heading
           globalHeading = 2;

           //update positon in maze
           posx = posx+1;
        }
        case 4: //dead end
        {
           //turn the mouse around and go back to previous cell
           turnAround2Fwd();
           getSensorState(); //updates walls and double checks sensors
                             //revert to best neighbor vale, relies on how many walls are surrounding neighbor cells
                             //this is best approach because now we know that dead end cell has walls
           nav2Neighbor(); //we are fucked if this returns a call to nav north.
           
           //will not update global heading in the hopes that nav2Neighbor resolves issue and bot goes to new cell 
        }
        case 5: //wall to left but none ahead or to right
        {
          //faster to keep going straight instaed of turning
          //move forward one cell
          fwdOneSquare();
          
          //increase the acutal positon value
          posy = posy-1;
        }
        case 6: //wall to right but none ahead or to left
        {
          //faster to keep going straight instaed of turning
          //move forward one cell
          fwdOneSquare();
          
          //increase the acutal positon value
          posy = posy-1;
        }
      }
      
    }
    
    //the robot is facing west
    case 8:
    {
      switch(sensorState)
      {
        case 1: //wall right and left
        {
          //move forward one cell
          fwdOneSquare();
          
          //increase the acutal positon value
          posx = posx-1;
        }
        case 2: //wall forward and left
        {
          //navigate to the cell next door
          rightOneSquare();

          //update global heading
          globalHeading = 1;

          //update positon in maze
          posy = posy+1;
        }
        case 3: //wall forward and right
        {
           //navigate to the left cell
           leftOneSquare();

           //update global heading
           globalHeading = 4;

           //update positon in maze
           posy = posy-1;
        }
        case 4: //dead end
        {
           //turn the mouse around and go back to previous cell
           turnAround2Fwd();
           getSensorState(); //updates walls and double checks sensors
                             //revert to best neighbor vale, relies on how many walls are surrounding neighbor cells
                             //this is best approach because now we know that dead end cell has walls
           nav2Neighbor(); //we are fucked if this returns a call to nav north.
           
           //will not update global heading in the hopes that nav2Neighbor resolves issue and bot goes to new cell 
        }
        case 5: //wall to left but none ahead or to right
        {
          //faster to keep going straight instaed of turning
          //move forward one cell
          fwdOneSquare();
          
          //increase the acutal positon value
          posx = posx-1;
        }
        case 6: //wall to right but none ahead or to left
        {
          //faster to keep going straight instaed of turning
          //move forward one cell
          fwdOneSquare();
          
          //increase the acutal positon value
          posx = posx-1;
        }
      }
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//defines the travel to the next EAST cell, dependant on surroudings
void navEast()
{
  //add self correction at somepoint
  switch(globalHeading)
  {
    //the robot is facing north
    case 1:
    {
      switch(sensorState)
      {
        case 1: //wall right and left
        {
          //move forward one cell
          fwdOneSquare();
          
          //increase the acutal positon value
          posy = posy+1;
        }
        case 2: //wall forward and left
        {
          //navigate to the cell next door
          rightOneSquare();

          //update global heading
          globalHeading = 2;

          //update positon in maze
          posx = posx+1;
        }
        case 3: //wall forward and right
        {
           //navigate to the left cell
           leftOneSquare();

           //update global heading
           globalHeading = 8;

           //update positon in maze
           posx = posx-1;
        }
        case 4: //dead end
        {
           //turn the mouse around and go back to previous cell
           turnAround2Fwd();
           getSensorState(); //updates walls and double checks sensors
                             //revert to best neighbor vale, relies on how many walls are surrounding neighbor cells
                             //this is best approach because now we know that dead end cell has walls
           nav2Neighbor(); //we are fucked if this returns a call to nav north.
           
           //will not update global heading in the hopes that nav2Neighbor resolves issue and bot goes to new cell 
        }
        case 5: //wall to left but none ahead or to right
        {
          //desire east, turn right
          //navigate to the cell next door
          rightOneSquare();

          //update global heading
          globalHeading = 2;

          //update positon in maze
          posx = posx+1;
        }
        case 6: //wall to right but none ahead or to left
        {
          //faster to keep going straight instaed of turning
          //move forward one cell
          fwdOneSquare();
          
          //increase the acutal positon value
          posy = posy+1;
        }
      }
    }
    
    //the robot is facing east
    case 2:
    {
      switch(sensorState)
      {
        case 1: //wall right and left
          {
            //move forward one cell
            fwdOneSquare();
            
            //increase the acutal positon value
            posx = posx+1;
          }
          case 2: //wall forward and left
          {
            //navigate to the cell next door
            rightOneSquare();
  
            //update global heading
            globalHeading = 4;
  
            //update positon in maze
            posy = posy-1;
          }
          case 3: //wall forward and right
          {
             //navigate to the left cell
             leftOneSquare();
  
             //update global heading
             globalHeading = 1;
  
             //update positon in maze
             posy = posy+1;
          }
          case 4: //dead end
          {
             //turn the mouse around and go back to previous cell
             turnAround2Fwd();
             getSensorState(); //updates walls and double checks sensors
                               //revert to best neighbor vale, relies on how many walls are surrounding neighbor cells
                               //this is best approach because now we know that dead end cell has walls
             nav2Neighbor(); //we are fucked if this returns a call to nav north.
             
             //will not update global heading in the hopes that nav2Neighbor resolves issue and bot goes to new cell 
          }
          case 5: //wall to left but none ahead or to right
          {
            //desire east go straight
            //faster to keep going straight instaed of turning
            //move forward one cell
            fwdOneSquare();
            
            //increase the acutal positon value
            posx = posx+1;
          }
          case 6: //wall to right but none ahead or to left
          {
            //desire east go staright
            //faster to keep going straight instaed of turning
            //move forward one cell
            fwdOneSquare();
            
            //increase the acutal positon value
            posx = posx+1;
          }
      }
    }
    
    //the robot is facing south
    case 4:
    {
      switch(sensorState)
      {
        case 1: //wall right and left
        {
          //move forward one cell
          fwdOneSquare();
          
          //increase the acutal positon value
          posy = posy-1;
        }
        case 2: //wall forward and left
        {
          //navigate to the cell next door
          rightOneSquare();

          //update global heading
          globalHeading = 8;

          //update positon in maze
          posx = posx-1;
        }
        case 3: //wall forward and right
        {
           //navigate to the left cell
           leftOneSquare();

           //update global heading
           globalHeading = 2;

           //update positon in maze
           posx = posx+1;
        }
        case 4: //dead end
        {
           //turn the mouse around and go back to previous cell
           turnAround2Fwd();
           getSensorState(); //updates walls and double checks sensors
                             //revert to best neighbor vale, relies on how many walls are surrounding neighbor cells
                             //this is best approach because now we know that dead end cell has walls
           nav2Neighbor(); //we are fucked if this returns a call to nav north.
           
           //will not update global heading in the hopes that nav2Neighbor resolves issue and bot goes to new cell 
        }
        case 5: //wall to left but none ahead or to right
        {
          //faster to keep going straight instaed of turning
          //move forward one cell
          fwdOneSquare();
          
          //increase the acutal positon value
          posy = posy-1;
        }
        case 6: //wall to right but none ahead or to left
        {
          //desire east go left
          //navigate to the left cell
           leftOneSquare();

           //update global heading
           globalHeading = 2;

           //update positon in maze
           posx = posx+1;
        }
      }
      
    }
      
    //the robot is facing west
    case 8:
    {
      switch(sensorState)
      {
        case 1: //wall right and left
        {
          //desire east, turn around and check cell ranking
          //turn the mouse around and go back to previous cell
           turnAround2Fwd();
           getSensorState(); //updates walls and double checks sensors
                             //revert to best neighbor vale, relies on how many walls are surrounding neighbor cells
                             //this is best approach because now we know that dead end cell has walls
           nav2Neighbor(); //we are fucked if this returns a call to nav north.
           
           //will not update global heading in the hopes that nav2Neighbor resolves issue and bot goes to new cell 
        }
        case 2: //wall forward and left
        {
          //navigate to the cell next door
          rightOneSquare();

          //update global heading
          globalHeading = 1;

          //update positon in maze
          posy = posy+1;
        }
        case 3: //wall forward and right
        {
           //navigate to the left cell
           leftOneSquare();

           //update global heading
           globalHeading = 4;

           //update positon in maze
           posy = posy-1;
        }
        case 4: //dead end
        {
           //turn the mouse around and go back to previous cell
           turnAround2Fwd();
           getSensorState(); //updates walls and double checks sensors
                             //revert to best neighbor vale, relies on how many walls are surrounding neighbor cells
                             //this is best approach because now we know that dead end cell has walls
           nav2Neighbor(); //we are fucked if this returns a call to nav north.
           
           //will not update global heading in the hopes that nav2Neighbor resolves issue and bot goes to new cell 
        }
        case 5: //wall to left but none ahead or to right
        {
          //turn the mouse around and go back to previous cell
           turnAround2Fwd();
           getSensorState(); //updates walls and double checks sensors
                             //revert to best neighbor vale, relies on how many walls are surrounding neighbor cells
                             //this is best approach because now we know that dead end cell has walls
           nav2Neighbor(); //we are fucked if this returns a call to nav north.
           
           //will not update global heading in the hopes that nav2Neighbor resolves issue and bot goes to new cell 
        }
        case 6: //wall to right but none ahead or to left
        {
          //turn the mouse around and go back to previous cell
           turnAround2Fwd();
           getSensorState(); //updates walls and double checks sensors
                             //revert to best neighbor vale, relies on how many walls are surrounding neighbor cells
                             //this is best approach because now we know that dead end cell has walls
           nav2Neighbor(); //we are fucked if this returns a call to nav north.
           
           //will not update global heading in the hopes that nav2Neighbor resolves issue and bot goes to new cell 
        }
      }
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//defines the travel to the next SOUTH cell, dependant on surroudings
void navSouth()
{
  //add self correction at somepoint
  switch(globalHeading)
  {
    //the robot is facing north
    case 1:
    {
      switch(sensorState)
      {
        case 1: //wall right and left
        {
          //desired is south, turn around
          //turn the mouse around and go back to previous cell
           turnAround2Fwd();
           getSensorState(); //updates walls and double checks sensors
                             //revert to best neighbor vale, relies on how many walls are surrounding neighbor cells
                             //this is best approach because now we know that dead end cell has walls
           nav2Neighbor(); 
           
           //will not update global heading in the hopes that nav2Neighbor resolves issue and bot goes to new cell
        }
        case 2: //wall forward and left
        {
          //navigate to the cell next door
          rightOneSquare();

          //update global heading
          globalHeading = 2;

          //update positon in maze
          posx = posx+1;
        }
        case 3: //wall forward and right
        {
           //navigate to the left cell
           leftOneSquare();

           //update global heading
           globalHeading = 8;

           //update positon in maze
           posx = posx-1;
        }
        case 4: //dead end
        {
           //turn the mouse around and go back to previous cell
           turnAround2Fwd();
           getSensorState(); //updates walls and double checks sensors
                             //revert to best neighbor vale, relies on how many walls are surrounding neighbor cells
                             //this is best approach because now we know that dead end cell has walls
           nav2Neighbor(); //we are fucked if this returns a call to nav north.
           
           //will not update global heading in the hopes that nav2Neighbor resolves issue and bot goes to new cell 
        }
        case 5: //wall to left but none ahead or to right
        {
          //desire south but this cell doesnt give enough information
          //turn the mouse around and go back to previous cell
          nav2Neighbor(); 
           
          //will not update global heading in the hopes that nav2Neighbor resolves issue and bot goes to new cell
        }
        case 6: //wall to right but none ahead or to left
        {
          //desired move is south turn about
          //turn the mouse around and go back to previous cell
           turnAround2Fwd();
           getSensorState(); //updates walls and double checks sensors
                             //revert to best neighbor vale, relies on how many walls are surrounding neighbor cells
                             //this is best approach because now we know that dead end cell has walls
           nav2Neighbor(); 
           
           //will not update global heading in the hopes that nav2Neighbor resolves issue and bot goes to new cell
        }
        default:
        {
          fwdOneCell();
          
        }
      }
    }
    
    //the robot is facing east
    case 2:
    {
      switch(sensorState)
      {
        case 1: //wall right and left
          {
            //move forward one cell
            fwdOneSquare();
            
            //increase the acutal positon value
            posx = posx+1;
          }
          case 2: //wall forward and left
          {
            //navigate to the cell next door
            rightOneSquare();
  
            //update global heading
            globalHeading = 4;
  
            //update positon in maze
            posy = posy-1;
          }
          case 3: //wall forward and right
          {
             //navigate to the left cell
             leftOneSquare();
  
             //update global heading
             globalHeading = 1;
  
             //update positon in maze
             posy = posy+1;
          }
          case 4: //dead end
          {
             //turn the mouse around and go back to previous cell
             turnAround2Fwd();
             getSensorState(); //updates walls and double checks sensors
                               //revert to best neighbor vale, relies on how many walls are surrounding neighbor cells
                               //this is best approach because now we know that dead end cell has walls
             nav2Neighbor(); //we are fucked if this returns a call to nav north.
             
             //will not update global heading in the hopes that nav2Neighbor resolves issue and bot goes to new cell 
          }
          case 5: //wall to left but none ahead or to right
          {
            //desired south opening to right, facing east
            //navigate to the cell next door
            rightOneSquare();
  
            //update global heading
            globalHeading = 4;
  
            //update positon in maze
            posy = posy-1;
          }
          case 6: //wall to right but none ahead or to left
          {
            //desire east go staright
            //faster to keep going straight instaed of turning
            //move forward one cell
            fwdOneSquare();
            
            //increase the acutal positon value
            posx = posx+1;
          }
      }
    }
    
    //the robot is facing south
    case 4:
    {
      switch(sensorState)
      {
        case 1: //wall right and left
        {
          //move forward one cell
          fwdOneSquare();
          
          //increase the acutal positon value
          posy = posy-1;
        }
        case 2: //wall forward and left
        {
          //navigate to the cell next door
          rightOneSquare();

          //update global heading
          globalHeading = 8;

          //update positon in maze
          posx = posx-1;
        }
        case 3: //wall forward and right
        {
           //navigate to the left cell
           leftOneSquare();

           //update global heading
           globalHeading = 2;

           //update positon in maze
           posx = posx+1;
        }
        case 4: //dead end
        {
           //turn the mouse around and go back to previous cell
           turnAround2Fwd();
           getSensorState(); //updates walls and double checks sensors
                             //revert to best neighbor vale, relies on how many walls are surrounding neighbor cells
                             //this is best approach because now we know that dead end cell has walls
           nav2Neighbor(); //we are fucked if this returns a call to nav north.
           
           //will not update global heading in the hopes that nav2Neighbor resolves issue and bot goes to new cell 
        }
        case 5: //wall to left but none ahead or to right
        {
          //faster to keep going straight instaed of turning
          //move forward one cell
          fwdOneSquare();
          
          //increase the acutal positon value
          posy = posy-1;
        }
        case 6: //wall to right but none ahead or to left
        {
          //desire east go left
          //navigate to the left cell
           leftOneSquare();

           //update global heading
           globalHeading = 2;

           //update positon in maze
           posx = posx+1;
        }
      }
      
    }
      
    //the robot is facing west
    case 8:
    {
      switch(sensorState)
      {
        case 1: //wall right and left
        {
          //desire east, turn around and check cell ranking
          //turn the mouse around and go back to previous cell
           turnAround2Fwd();
           getSensorState(); //updates walls and double checks sensors
                             //revert to best neighbor vale, relies on how many walls are surrounding neighbor cells
                             //this is best approach because now we know that dead end cell has walls
           nav2Neighbor(); //we are fucked if this returns a call to nav north.
           
           //will not update global heading in the hopes that nav2Neighbor resolves issue and bot goes to new cell 
        }
        case 2: //wall forward and left
        {
          //navigate to the cell next door
          rightOneSquare();

          //update global heading
          globalHeading = 1;

          //update positon in maze
          posy = posy+1;
        }
        case 3: //wall forward and right
        {
           //navigate to the left cell
           leftOneSquare();

           //update global heading
           globalHeading = 4;

           //update positon in maze
           posy = posy-1;
        }
        case 4: //dead end
        {
           //turn the mouse around and go back to previous cell
           turnAround2Fwd();
           getSensorState(); //updates walls and double checks sensors
                             //revert to best neighbor vale, relies on how many walls are surrounding neighbor cells
                             //this is best approach because now we know that dead end cell has walls
           nav2Neighbor(); //we are fucked if this returns a call to nav north.
           
           //will not update global heading in the hopes that nav2Neighbor resolves issue and bot goes to new cell 
        }
        case 5: //wall to left but none ahead or to right
        {
          //turn the mouse around and go back to previous cell
           turnAround2Fwd();
           getSensorState(); //updates walls and double checks sensors
                             //revert to best neighbor vale, relies on how many walls are surrounding neighbor cells
                             //this is best approach because now we know that dead end cell has walls
           nav2Neighbor(); //we are fucked if this returns a call to nav north.
           
           //will not update global heading in the hopes that nav2Neighbor resolves issue and bot goes to new cell 
        }
        case 6: //wall to right but none ahead or to left
        {
          //turn the mouse around and go back to previous cell
           turnAround2Fwd();
           getSensorState(); //updates walls and double checks sensors
                             //revert to best neighbor vale, relies on how many walls are surrounding neighbor cells
                             //this is best approach because now we know that dead end cell has walls
           nav2Neighbor(); //we are fucked if this returns a call to nav north.
           
           //will not update global heading in the hopes that nav2Neighbor resolves issue and bot goes to new cell 
        }
      }
    }
  }
}

//defines the travel to the next WEST cell, dependant on surroudings
void navWest()
{
  
}
