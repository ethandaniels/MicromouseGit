/*
  Ethan Daniels || Micromouse 2017-2018
  Last Edited 7.5.2017 6:17PM  
  
  Includes the floodfill algorithmic approaches 
*/



//Defining the wall byte LSB->MSB
const int north = 1;
const int east = 2;
const int south = 4;
const int west = 8;   
const int visited = 16;

//defualt state is north
int globalHeading = 1;

//define the maze size
int maze [16][16];

//define cell values (based on wall byte) 
const int startCell = south+west+east;
int currCell = startCell;

//define actual position values
int posx = 1;
int posy = 1;
const int goalx = 8;
const int goaly = 8;

int dist2Goal(int posx, int posy)
{
  int dist = (abs(goaly-posy)+abs(goalx-posx));
  return dist;
}

//will explore the maze and attempt to find the center tile
void basicFloodfill()
{
  while((posx && posy) != (8 || 9))
  {
    //if this cell has been visited
    if(maze[posx][posy] >= 16)
    {
      nav2Center();
    }
    //if the cell has been visited
    else
    {
      getSensorState();
      nav2Center();
    }
  }
}

//should implement the cell rank finding function [note will need button to reset all positon values]
void knownFloodfill()
{
  
}
