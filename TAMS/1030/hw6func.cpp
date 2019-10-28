#include "hw6prgrm.h"
using namespace std;

/*
===============================================================================
Function    : initial
Parameters  : none
Returns     : void
Description : Function outputs the initial display
===============================================================================
*/
void initial()
{
  cout << "Department:     Computer Science\n"
       << "Course Number:  CSCE 1030\n"
       << "Name:           David Zhao\n"
       << "EUID:           dz0086\n"
       << "Email:          davidzhao@unt.edu\n";

       return;
}
/*
===============================================================================
Function    : intro
Parameters  : none
Returns     : void
Description : Function outputs the introduction to Stratego, including rules
===============================================================================
*/
void intro()
{
  cout << " W e l c o m e   t o    1 0 3 0    S t r a t e g o\n"
       << "-----------------------------------------------------------------------\n";
  cout << "This program will set up a 5x5 game board for a 1030 version of the game\n"
       << "of Stratego. One player will compete against the computer, each assigned\n"
       << "10 total pieces consisting of the following:\n"
       << "  1 Flag (F)\n"
       << "  3 BOMB (B)\n"
       << "  1 Marshal (1) or GENERAL (2)\n"
       << "  3 COLONEL (3), MAJOR (4), CAPTAIN (5), LIEUTENANT (6), or SERGEANT (7)\n"
       << "  1 MINER (8)\n"
       << "  1 SPY (S)\n";
  cout << "GENERAL RULES:\n"
       << "--------------\n"
       << "For the most part, the game will follow the standard Stratego rules, although\n"
       << "there are some exceptions.\n"
       << "1. Both players (BLUE and RED) will have all of their 10 game pieces as-\n"
       << "   signed randomly with the only requirement being that the FLAG must be\n"
       << "   placed in the back row. RED will start the game first.\n"
       << "2. Higher ranked pieces can capture lower ranked pieces in the following\n"
       << "   order: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> S, meaning that 1 (the\n"
       << "   MARSHAL) can remove 2 (the GENERAL) and so forth. The MINER (8) piece\n"
       << "   may strike a BOMB and remove it to occupy the now unoccupied space. A\n"
       << "   SPY (S), although the lowest ranked piece, may remove the MARSHAL (1)\n"
       << "   or the GENERAL (2). When pieces have equal rank, then both pieces are\n"
       << "   removed.\n"
       << "3. The FLAG and BOMBs are not moveable while all of the other pieces may\n"
       << "   move one square at a time forward, backward, or sideward, but not di-\n"
       << "   agonally to an open square.\n"
       << "4. A player must either move or strike on his/her turn.\n"
       << "5. The game ends when a player strikes his/her opponent's flag.\n"
       << "------------------------------------------------------------------------\n";
}
/*
===============================================================================
Function    : boardInit
Parameters  : the array for the board and the array for the colors of the pieces
Returns     : void
Description : Function initializes the board to ensure it's not full of garbage
===============================================================================
*/
void boardInit(pieceType **board, int boardSize)
{
  //nested for loop for setting each element to the '0' of the type, sort of
  for(int i = 0; i < boardSize; i++)
  {
    for(int j = 0; j < boardSize; j++)
    {
      board[i][j].rank = EMPTY;
      board[i][j].side = NONE;
    }
  }
}
/*
===============================================================================
Function    : assignPieces
Parameters  : array for the board and array for the colors of the pieces
Returns     : void
Description : Function sets up the board using randomly generated pieces
===============================================================================
*/
void assignPieces(pieceType **board, int boardSize)
{
  //set up a bunch of variables used to temporarily store randomly generated values
  int temp1, temp2, temp3, temp5, temp6;
  pieces temp4;
  srand(time(NULL));
  //setting blue flag
  temp1 = rand() % 5;
  //cout << temp1 << "Bomb loc\n";
  board[0][temp1].rank = FLAG;
  board[0][temp1].side = BLUE;
  //setting blue bombs
  for (int k = 0; k < 3; k++)
  {
      //do while loop to make sure not setting bombs where previous placements are
    do {
      temp1 = rand() % 5;
      temp2 = rand() % 2;
      //cout << temp1 << endl << temp2 << endl;
    } while(board[temp2][temp1].rank != EMPTY);
    board[temp2][temp1].rank = BOMB;
    board[temp2][temp1].side = BLUE;
    //cout << static_cast<char>(board[temp2][temp1]) << endl;
  }
  //setting blue marshal or general
  do {
    temp1 = rand() % 5;
    temp2 = rand() % 2;
    temp3 = rand() % 2 + 1;
    temp4 = static_cast<pieces>(temp3);
    //cout << temp3 << endl;
  } while(board[temp2][temp1].rank != EMPTY);
  board[temp2][temp1].rank = temp4;
  board[temp2][temp1].side = BLUE;
  //setting miner
  do {
    temp1 = rand() % 5;
    temp2 = rand() % 2;
  } while(board[temp2][temp1].rank != EMPTY);
  board[temp2][temp1].rank = MINER;
  board[temp2][temp1].side = BLUE;
  //setting spy
  do {
    temp1 = rand() % 5;
    temp2 = rand() % 2;
  } while(board[temp2][temp1].rank != EMPTY);
  board[temp2][temp1].rank = SPY;
  board[temp2][temp1].side = BLUE;
  //setting colonel, major, captain, lieutenant, and sergeants
  for (int l = 0; l < 3; l++)
  {
      //do while loop to make sure not setting officers where previous placements are
      do {
        temp1 = rand() % 5;
        temp2 = rand() % 2;
        temp3 = rand() % 5 + 3;
        temp4 = static_cast<pieces>(temp3);
      } while(board[temp2][temp1].rank != EMPTY);
      board[temp2][temp1].rank = temp4;
      board[temp2][temp1].side = BLUE;
  }
  //setting red flag
  temp1 = rand() % 5;
  //cout << temp1 << "Bomb loc\n";
  board[4][temp1].rank = FLAG;
  board[4][temp1].side = RED;
  //setting red bombs
  for (int k = 0; k < 3; k++)
  {
      //do while loop to make sure not setting bombs where previous placements are
    do {
      temp1 = rand() % 5;
      temp2 = rand() % 2 + 3;
      //cout << temp1 << endl << temp2 << endl;
    } while(board[temp2][temp1].rank != EMPTY);
    board[temp2][temp1].rank = BOMB;
    board[temp2][temp1].side = RED;
    //cout << static_cast<char>(board[temp2][temp1]) << endl;
  }
  //setting red marshal or general
  do {
    temp1 = rand() % 5;
    temp2 = rand() % 2 + 3;
    temp3 = rand() % 2 + 1;
    temp4 = static_cast<pieces>(temp3);
    //cout << temp3 << endl;
  } while(board[temp2][temp1].rank != EMPTY);
  board[temp2][temp1].rank = temp4;
  board[temp2][temp1].side = RED;
  //setting miner
  do {
    temp1 = rand() % 5;
    temp2 = rand() % 2 + 3;
  } while(board[temp2][temp1].rank != EMPTY);
  board[temp2][temp1].rank = MINER;
  board[temp2][temp1].side = RED;
  //setting spy
  do {
    temp1 = rand() % 5;
    temp2 = rand() % 2 + 3;
  } while(board[temp2][temp1].rank != EMPTY);
  board[temp2][temp1].rank = SPY;
  board[temp2][temp1].side = RED;
  //setting colonel, major, captain, lieutenant, and sergeants
  for (int l = 0; l < 3; l++)
  {
      //do while loop to make sure not setting officers where previous placements are
      do {
        temp1 = rand() % 5;
        temp2 = rand() % 2 + 3;
        temp3 = rand() % 5 + 3;
        temp4 = static_cast<pieces>(temp3);
      } while(board[temp2][temp1].rank != EMPTY);
      board[temp2][temp1].rank = temp4;
      board[temp2][temp1].side = RED;
  }
}
/*
===============================================================================
Function    : displayBoard
Parameters  : array for the board, array for the colors of the pieces, and size of the board
Returns     : void
Description : Function displays the set up board
===============================================================================
*/
void displayBoard(pieceType **board, int boardSize, bool reveal)
{
  //declaring necessary variables
  int leftLetter, boardInt;
  //printing top of the board
  cout << "    1 2 3 4 5\n";
  cout << "  +-----------+\n";
  //printing content of the board
  for (int i = 0; i < boardSize; i++)
  {
    //printing letters to the left
    leftLetter = i + 65;
    cout << static_cast<char>(leftLetter) << " | ";
      //printing actual pieces along with proper color
      for (int j = 0; j < boardSize; j++)
      {
        if (board[i][j].side == RED)
        {
          if(board[i][j].rank < 30)
          {
            boardInt = board[i][j].rank + 48;
            printf("\033[1;31m%c\033[0m ", static_cast<char>(boardInt));
            //cout << static_cast<char>(boardInt) << " ";
          }
          else
          {
            printf("\033[1;31m%c\033[0m ", static_cast<char>(board[i][j].rank));
            //cout << static_cast<char>(board[i][j]) << ' ';
          }
        }
        else if (board[i][j].side == BLUE && (reveal == true))
        {
          if(board[i][j].rank < 30)
          {
            boardInt = board[i][j].rank + 48;
            printf("\033[1;34m%c\033[0m ", static_cast<char>(boardInt));
            //cout << static_cast<char>(boardInt) << " ";
          }
          else
          {
            printf("\033[1;34m%c\033[0m ", static_cast<char>(board[i][j].rank));
            //cout << static_cast<char>(board[i][j]) << ' ';
          }
        }
        else if (board[i][j].side == BLUE && (reveal == false))
        {
          printf("\033[1;34mX\033[0m ");
            //cout << static_cast<char>(boardInt) << " ";
        }
        else
        {
          printf("  ");
        }
      }
      //printing last little | of the board
      cout << "|\n";
  }
    //printing bottom of the board
    cout << "  +-----------+\n";
}

bool updateBoard(pieceType **board, int oldX, int oldY, int newX, int newY, bool reveal, int boardSize)
{
  //declaring necessary variables
  int leftLetter, boardInt;
  int xLoc = oldX + 49;
  int yLoc = oldY + 65;
  int newXnum = newX + 49;
  int newYnum = newY + 65;
  char y, x;
  if (board[oldY][oldX].rank > 65)
  {
    y = board[oldY][oldX].rank;
  }
  if (board[oldY][oldX].rank < 58)
  {
    y = board[oldY][oldX].rank + 48;
  }
  if (board[newY][newX].rank > 65)
  {
    x = board[newY][newX].rank;
  }
  if (board[newY][newX].rank < 58)
  {
    x = board[newY][newX].rank + 48;
  }
  //checking to see if game is over
  if (board[newY][newX].rank == FLAG)
  {
    return true;
  }
  else if(board[newY][newX].rank == EMPTY)
  {
    cout << "RED " << y << " moves from " << static_cast<char>(yLoc) << static_cast<char>(xLoc) << " to " << static_cast<char>(newYnum) << static_cast<char>(newXnum) << ".\n";
    board[newY][newX].rank = board[oldY][oldX].rank;
    board[oldY][oldX].rank = EMPTY;
    board[newY][newX].side = board[oldY][oldX].side;
    board[oldY][oldX].side = NONE;
  }
  else if ((board[newY][newX].rank == BOMB) && (board[oldY][oldX].rank != 8))
  {
    cout << "RED " << y << " at " << static_cast<char>(yLoc) << static_cast<char>(xLoc) << " blown up by BLUE B at " << static_cast<char>(newYnum) << static_cast<char>(newXnum) << ".\n";
    board[oldY][oldX].rank = EMPTY;
    board[oldY][oldX].side = NONE;
  }
  else if ((board[newY][newX].rank == BOMB) && (board[oldY][oldX].rank == 8))
  {
    cout << "RED " << y << " at " << static_cast<char>(yLoc) << static_cast<char>(xLoc) << " defuse BLUE B at " << static_cast<char>(newYnum) << static_cast<char>(newXnum) << ".\n";
    board[newY][newX].rank = board[oldY][oldX].rank;
    board[oldY][oldX].rank = EMPTY;
    board[newY][newX].side = board[oldY][oldX].side;
    board[oldY][oldX].side = NONE;
  }
  else if ((board[newY][newX].rank == SPY) && ((board[oldY][oldX].rank == 1) || (board[oldY][oldX].rank == 2)))
  {
    cout << "RED " << y << " at " << static_cast<char>(yLoc) << static_cast<char>(xLoc) << " captured by BLUE S at " << static_cast<char>(newYnum)<<static_cast<char>(newXnum)<<".\n";
    board[oldY][oldX].rank = EMPTY;
    board[oldY][oldX].side = NONE;
  }
  else if (((board[newY][newX].rank == 1) || (board[newY][newX].rank == 2)) && (board[oldY][oldX].rank == SPY))
  {
    cout << "RED " << y << " at " << static_cast<char>(yLoc) << static_cast<char>(xLoc) << " captures BLUE " << x << " at " << static_cast<char>(newYnum)<<static_cast<char>(newXnum)<<".\n";
    board[newY][newX].rank = board[oldY][oldX].rank;
    board[oldY][oldX].rank = EMPTY;
    board[newY][newX].side = board[oldY][oldX].side;
    board[oldY][oldX].side = NONE;
  }
  else if ((board[newY][newX].rank == SPY) && (board[oldY][oldX].rank != SPY))
  {
    cout << "RED " << y << " at " << static_cast<char>(yLoc) << static_cast<char>(xLoc) << " captures BLUE S at " << static_cast<char>(newYnum)<<static_cast<char>(newXnum)<<".\n";
    board[newY][newX].rank = board[oldY][oldX].rank;
    board[oldY][oldX].rank = EMPTY;
    board[newY][newX].side = board[oldY][oldX].side;
    board[oldY][oldX].side = NONE;
  }
  else if (board[newY][newX].rank > board[oldY][oldX].rank)
  {
    cout << "RED " << y << " at " << static_cast<char>(yLoc) << static_cast<char>(xLoc)<< " captures BLUE " << x << " at " << static_cast<char>(newYnum)<<static_cast<char>(newXnum)<<".\n";
    board[newY][newX].rank = board[oldY][oldX].rank;
    board[oldY][oldX].rank = EMPTY;
    board[newY][newX].side = board[oldY][oldX].side;
    board[oldY][oldX].side = NONE;
  }
  else if (board[newY][newX].rank < board[oldY][oldX].rank)
  {
    cout << "RED " << y << " at " << static_cast<char>(yLoc) << static_cast<char>(xLoc) << " captured by BLUE " << x << " at " << static_cast<char>(newYnum)<<static_cast<char>(newXnum)<<".\n";
    board[oldY][oldX].rank = EMPTY;
    board[oldY][oldX].side = NONE;
  }
  else if (board[newY][newX].rank == board[oldY][oldX].rank)
  {
    cout << "RED " << y << " at " << static_cast<char>(yLoc) << static_cast<char>(xLoc) << " captures BLUE " << x << " at " << static_cast<char>(newYnum)<<static_cast<char>(newXnum)<<" and is captured itself.\n";
    board[oldY][oldX].rank = EMPTY;
    board[newY][newX].rank = EMPTY;
    board[oldY][oldX].side = NONE;
    board[newY][newX].side = NONE;
  }
  //printing top of the board
  cout << "    1 2 3 4 5\n";
  cout << "  +-----------+\n";
  //printing content of the board
  for (int i = 0; i < boardSize; i++)
  {
    //printing letters to the left
    leftLetter = i + 65;
    cout << static_cast<char>(leftLetter) << " | ";
      //printing actual pieces along with proper color
      for (int j = 0; j < boardSize; j++)
      {
        if (board[i][j].side == RED)
        {
          if(board[i][j].rank < 30)
          {
            boardInt = board[i][j].rank + 48;
            printf("\033[1;31m%c\033[0m ", static_cast<char>(boardInt));
            //cout << static_cast<char>(boardInt) << " ";
          }
          else
          {
            printf("\033[1;31m%c\033[0m ", static_cast<char>(board[i][j].rank));
            //cout << static_cast<char>(board[i][j]) << ' ';
          }
        }
        else if (board[i][j].side == BLUE && (reveal == true))
        {
          if(board[i][j].rank < 30)
          {
            boardInt = board[i][j].rank + 48;
            printf("\033[1;34m%c\033[0m ", static_cast<char>(boardInt));
            //cout << static_cast<char>(boardInt) << " ";
          }
          else
          {
            printf("\033[1;34m%c\033[0m ", static_cast<char>(board[i][j].rank));
            //cout << static_cast<char>(board[i][j]) << ' ';
          }
        }
        else if (board[i][j].side == BLUE && (reveal == false))
        {
          printf("\033[1;34mX\033[0m ");
            //cout << static_cast<char>(boardInt) << " ";
        }
        else
        {
          printf("  ");
        }
      }
      //printing last little | of the board
      cout << "|\n";
  }
    //printing bottom of the board
    cout << "  +-----------+\n";
    return false;
}
