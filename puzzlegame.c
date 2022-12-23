#include <stdio.h>
int board [4][4] ={ //Create the board and set it up in reverse order
  {15,14,13,12},//Game Board  for the start of the game 
  {11,10,9,8},
  {7,6,5,4},
  {3,2,1,0}
  };
int initialization(void); //Predefines all methods to prevent error
int teardown(void);
int print(void);
int move(int);
const int boardSize = 4; //Locks in the size of the game board so it cannot be changed
int main(void) {
  char input = 't'; //Allows the game to begin at least once
  int tileNumber; //Stores User's Entered number to be used in later methods
  initialization(); // Begins the game
  while(input != 'q') // Game Loop
  {
    printf("Menu: [p]rint, [m]ove, [q]uit? \n"); 
    scanf("%c",&input); // Reads the users selection of the user
    if(input == 'p')
    {
      print(); // Calls the print method
    }
    else if(input == 'm')
    {
      printf("Which tile would you like to move \n"); 
      scanf("%d", &tileNumber); //Reads the Tile number the user wants to me
      printf("Moving %d.\n", tileNumber);
      move(tileNumber); //Calls the Move method so the board can be changed 
    }
  }
  teardown(); //Ends the game
  return 0;
}
int initialization(void)
{
  printf("Setting up the game \n"); // Lets the player know the game is starting
  return 0;
}
int teardown(void)
{
  printf("Ending the Game"); // Lets the user know the game is ending 
  return 0;
}
int display(void)
{
  for(int i = 0; i< 4; i++)  // changes the column of the 2d array after each column is printed
  {
    for(int j= 0; j< 4; j++) // Goes through the rows of the array
    {

      if(board[i][j] != 0) 
      {
        printf("%3d ", board[i][j]); // Prints the index of the array dependent on j, and i value
      }
      else 
      {
        printf("    "); //Makes a blank space instead of zero so the user knows where the open spot is where they can move numbers 
      }
    }
    printf("\n"); //Adds a new line after the row is printed so the game is set up as a 4x4 
  }
  return 0;
}
int print(void)
  {
    display(); 
    return 0;
  }
int move(int tile)
{
  int x1; 
  int y1;
  int x2;
  int y2;
  if(tile >= 16) //Doesn't let the user enter any numbers not on the board
  {
    printf("Invalid move \n");
    return 0;
  }
  for(int i = 0; i< 4; i++) // changes the column of the 2d array after each column is traversed
  {
    for(int j= 0; j< 4; j++)  // Goes through the rows of the array while it is being traversed to search for the users number
    {
      if(board[i][j] == 0) //Storing Index values allows for easy swapping of tiles
      {
        x1 = i; //Stores i index value so it can be swapped later
        y1 = j; //Stores i index value so it can be swapped later
      }
      else if(board[i][j] == tile)//Storing Index values allows for easy swapping of tiles
      { 
        x2 = i; //Stores i index value so it can be swapped later
        y2 = j; //Stores j index value so it can be swapped later
      }
    }
  }  
    for(int i = 0; i< 4; i++) // changes the column of the 2d array after each column is traversed
  {
    for(int j= 0; j< 4; j++)  // Goes through the rows of the array while it is being traversed to search for the users number
    {
      if(board[i][j] == tile) 
      {
        if(x1 == x2 && (y1 == y2+1 || y1 == y2-1)) //Checks to see if the element next to the called tile is zero. Also Keeps array in bounds
        {
          board[x1][y1] = tile; //Makes the appropriate swap
          board[x2][y2] = 0; //Makes the appropriate swap
        }
        else if(y1 == y2 && (x1 == x2+1 || x1 == x2-1)) //Checks to see if the element next to the called tile is zero. Also Keeps array in bounds
        {
          board[x1][y1] = tile; //Makes the appropriate swap
          board[x2][y2] = 0; //Makes the appropriate swap
        }
        else
        {
          printf("Invalid Move \n");
        }
      }
    }
  }
  return 0;
}
