/*
===============================================================================
Name        : homework5.cpp
Author      : David Zhao
Date        : 11-18-17
Description : Program prints out the rules of Stratego then prints out a randomly
              generated board.
===============================================================================
*/
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
using namespace std;

enum pieces {EMPTY = ' ', MARSHAL = 1, GENERAL = 2, COLONEL = 3, MAJOR = 4, CAPTAIN = 5, LIEUTENANT = 6, SERGEANT = 7, MINER = 8, SPY = 'S', FLAG = 'F', BOMB = 'B'};
enum color {NONE, RED, BLUE};
const int SIZE = 5;

void initial();
void intro();
void boardInit(pieces board[][5], color side[][5], int boardSize);
void assignPieces(pieces board[][5], color side[][5], int boardSize);
void displayBoard(pieces board[][5], color side[][5], int boardSize);

int main()
{
  initial();
  intro();

  pieces board[5][5];
  color side[5][5];

  boardInit(board, side, SIZE);
  assignPieces(board, side, SIZE);
  displayBoard(board, side, SIZE);

  return 0;
}


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
       << "   or the GENERAL (2).\n"
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
void boardInit(pieces board[][5], color side[][5], int boardSize)
{
  //nested for loop for setting each element to the '0' of the type, sort of
  for(int i = 0; i < boardSize; i++)
  {
    for(int j = 0; j < boardSize; j++)
    {
      board[i][j] = EMPTY;
      side[i][j] = NONE;
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
void assignPieces(pieces board[][5], color side[][5], int boardSize)
{
  //set up a bunch of variables used to temporarily store randomly generated values
  int temp1, temp2, temp3, temp5, temp6;
  pieces temp4;
  srand(time(NULL));
  //setting blue flag
  temp1 = rand() % 5;
  //cout << temp1 << "Bomb loc\n";
  board[0][temp1] = FLAG;
  side[0][temp1] = BLUE;
  //setting blue bombs
  for (int k = 0; k < 3; k++)
  {
      //do while loop to make sure not setting bombs where previous placements are
    do {
      temp1 = rand() % 5;
      temp2 = rand() % 2;
      //cout << temp1 << endl << temp2 << endl;
    } while(board[temp2][temp1] != EMPTY);
    board[temp2][temp1] = BOMB;
    side[temp2][temp1] = BLUE;
    //cout << static_cast<char>(board[temp2][temp1]) << endl;
  }
  //setting blue marshal or general
  do {
    temp1 = rand() % 5;
    temp2 = rand() % 2;
    temp3 = rand() % 2 + 1;
    temp4 = static_cast<pieces>(temp3);
    //cout << temp3 << endl;
  } while(board[temp2][temp1] != EMPTY);
  board[temp2][temp1] = temp4;
  side[temp2][temp1] = BLUE;
  //setting miner
  do {
    temp1 = rand() % 5;
    temp2 = rand() % 2;
  } while(board[temp2][temp1] != EMPTY);
  board[temp2][temp1] = MINER;
  side[temp2][temp1] = BLUE;
  //setting spy
  do {
    temp1 = rand() % 5;
    temp2 = rand() % 2;
  } while(board[temp2][temp1] != EMPTY);
  board[temp2][temp1] = SPY;
  side[temp2][temp1] = BLUE;
  //setting colonel, major, captain, lieutenant, and sergeants
  for (int l = 0; l < 3; l++)
  {
      //do while loop to make sure not setting officers where previous placements are
      do {
        temp1 = rand() % 5;
        temp2 = rand() % 2;
        temp3 = rand() % 5 + 3;
        temp4 = static_cast<pieces>(temp3);
      } while(board[temp2][temp1] != EMPTY);
      board[temp2][temp1] = temp4;
      side[temp2][temp1] = BLUE;
  }
  //setting red flag
  temp1 = rand() % 5;
  //cout << temp1 << "Bomb loc\n";
  board[4][temp1] = FLAG;
  side[4][temp1] = RED;
  //setting red bombs
  for (int k = 0; k < 3; k++)
  {
      //do while loop to make sure not setting bombs where previous placements are
    do {
      temp1 = rand() % 5;
      temp2 = rand() % 2 + 3;
      //cout << temp1 << endl << temp2 << endl;
    } while(board[temp2][temp1] != EMPTY);
    board[temp2][temp1] = BOMB;
    side[temp2][temp1] = RED;
    //cout << static_cast<char>(board[temp2][temp1]) << endl;
  }
  //setting red marshal or general
  do {
    temp1 = rand() % 5;
    temp2 = rand() % 2 + 3;
    temp3 = rand() % 2 + 1;
    temp4 = static_cast<pieces>(temp3);
    //cout << temp3 << endl;
  } while(board[temp2][temp1] != EMPTY);
  board[temp2][temp1] = temp4;
  side[temp2][temp1] = RED;
  //setting miner
  do {
    temp1 = rand() % 5;
    temp2 = rand() % 2 + 3;
  } while(board[temp2][temp1] != EMPTY);
  board[temp2][temp1] = MINER;
  side[temp2][temp1] = RED;
  //setting spy
  do {
    temp1 = rand() % 5;
    temp2 = rand() % 2 + 3;
  } while(board[temp2][temp1] != EMPTY);
  board[temp2][temp1] = SPY;
  side[temp2][temp1] = RED;
  //setting colonel, major, captain, lieutenant, and sergeants
  for (int l = 0; l < 3; l++)
  {
      //do while loop to make sure not setting officers where previous placements are
      do {
        temp1 = rand() % 5;
        temp2 = rand() % 2 + 3;
        temp3 = rand() % 5 + 3;
        temp4 = static_cast<pieces>(temp3);
      } while(board[temp2][temp1] != EMPTY);
      board[temp2][temp1] = temp4;
      side[temp2][temp1] = RED;
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
void displayBoard(pieces board[][5], color side[][5], int boardSize)
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
        if (side[i][j] == RED)
        {
          if(board[i][j] < 30)
          {
            boardInt = board[i][j] + 48;
            printf("\033[1;31m%c\033[0m ", static_cast<char>(boardInt));
            //cout << static_cast<char>(boardInt) << " ";
          }
          else
          {
            printf("\033[1;31m%c\033[0m ", static_cast<char>(board[i][j]));
            //cout << static_cast<char>(board[i][j]) << ' ';
          }
        }
        else if (side[i][j] == BLUE)
        {
          if(board[i][j] < 30)
          {
            boardInt = board[i][j] + 48;
            printf("\033[1;34m%c\033[0m ", static_cast<char>(boardInt));
            //cout << static_cast<char>(boardInt) << " ";
          }
          else
          {
            printf("\033[1;34m%c\033[0m ", static_cast<char>(board[i][j]));
            //cout << static_cast<char>(board[i][j]) << ' ';
          }
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
