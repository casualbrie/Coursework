#include <iostream>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <cmath>
using namespace std;

enum pieces {EMPTY = ' ', MARSHAL = 1, GENERAL = 2, COLONEL = 3, MAJOR = 4, CAPTAIN = 5, LIEUTENANT = 6, SERGEANT = 7, MINER = 8, SPY = 'S', FLAG = 'F', BOMB = 'B'};
enum color {NONE, RED, BLUE};
const int SIZE = 5;

struct pieceType
{
  pieces rank;
  color side;
  bool canMove;
};

typedef pieceType* BoardArray;

void initial();
void intro();
void boardInit(pieceType **board, int boardSize);
void assignPieces(pieceType **board, int boardSize);
void displayBoard(pieceType **board, int boardSize, bool reveal);
bool updateBoard(pieceType **board, int xLoc, int yLoc, int newX, int newY, bool reveal, int boardSize);
