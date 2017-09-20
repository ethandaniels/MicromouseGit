//Defining the wall byte LSB->MSB
const int north = 1;
const int east = 2;
const int south = 4;
const int west = 8;   
const int visited = 16;
const int onRoute = 32;

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



void floodFill()
{
  while(maze[posx][posy] != (maze[8][8] || maze[8][9] || maze[9][8] || maze[9][9]))
  {
    getSensorState();
    nav2Neighbor();
  }
  //succesful when mouse reaches any of these squares or current cell value is less than or equal to 8
  //  const int goal1 = maze[8][8]; 
  //  const int goal2 = maze[8][9];
  //  const int goal3 = maze[9][8];
  //  const int goal4 = maze[9][9];
  
}

int dist2Goal(int posx, int posy)
{
  int dist = (abs(goaly-posy)+abs(goalx-posx));
  return dist;
}

//void getNeighbors(int* nextx, int* nexty)
//{
//  //these will be referneced in nav2Neighbor
//  //create north neighbor
//  int northx = posx;
//  int northy = posy+1;
//
//  //create east neighbor
//  int eastx = posx+1;
//  int easty = posy;
//  
//  //create south neighbor
//  int southx = posx;
//  int southy = posy-1;
//
//  //create weast neighbor
//  int westx = posx-1;
//  int westy = posy;
//
//  //if the WALL BYTE value of the north cell is the least, we want next cell to be there
//  if(maze[northx][northy] < (maze[southx][southy] || maze[eastx][easty] || maze[westx][westy]))
//  {
//    *nextx = northx;
//    *nexty = northy;
//  }
//  //ibid. east
//  if(maze[eastx][easty] < maze[northx][northy] || (maze[southx][southy] || maze[westx][westy]))
//  {
//    *nextx = eastx;
//    *nexty = easty;
//  }
//  //ibid. south
//  if((maze[southx][southy] < maze[northx][northy] || maze[eastx][easty] || maze[westx][westy]))
//  {
//    *nextx = southx;
//    *nexty = southy;
//  }
//  //ibid. west
//  if((maze[westx][westy] < maze[northx][northy] || maze[eastx][easty] || maze[southx][southy]))
//  {
//    *nextx = westx;
//    *nexty = westy;
//  }
//}
