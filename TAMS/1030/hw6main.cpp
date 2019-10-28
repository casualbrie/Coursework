/*
===============================================================================
Name        : homework5.cpp
Author      : David Zhao
Date        : 11-18-17
Description : Program prints out the rules of Stratego then prints out a randomly
              generated board.
===============================================================================
*/
#include "hw6prgrm.h"
using namespace std;



int main()
{
  initial();
  intro();


  char rowOld, colOld, rowNew, colNew, coordOld[3], coordNew[3];
  BoardArray *board = new pieceType*[SIZE];
  for(int i = 0; i < SIZE; i++)
  {
    board[i] = new pieceType[SIZE];
  }
  //color side[5][5];
  bool endGame = false;

  boardInit(board, SIZE);
  assignPieces(board, SIZE);
  displayBoard(board, SIZE, endGame);
  //cout << static_cast<char>(board[1][1].rank);
  while(endGame == false)
  {
    cout << "RED MOVE: Enter current coordinates of piece (e.g., D2, or QQ to quit): ";
    cin >> coordOld;
    //splitting up the coordinates
    rowOld = coordOld[0];
    colOld = coordOld[1];
    if ((rowOld == 'Q') && (colOld == 'Q'))
    {
      cout << "RED player forfeits game. Please play again soon!\n";
      break;
    }
    //checking for valid coordinates
    if (((rowOld < 65) || (rowOld > 69)) || ((colOld < 49) || (colOld > 53)) || (board[rowOld-65][colOld-49].rank == EMPTY) || (board[rowOld-65][colOld-49].side == BLUE) || ((board[rowOld-65][colOld-49].rank == BOMB) || (board[rowOld-65][colOld-49].rank == FLAG)))
    {
      cout << "Invalid coordinates " << rowOld << colOld << ". Try again...\n";
      continue;
    }
    cout << "RED MOVE: Enter new coordinates of piece at " << rowOld << colOld << ": ";
    cin >> coordNew;
    //splitting up the coordinates
    rowNew = coordNew[0];
    colNew = coordNew[1];
    //checking for valid coordinates
    if (((rowNew < 65) || (rowNew > 69)) || ((colNew < 49) || (colNew > 53)) || ((colNew != colOld) && (rowNew != rowOld)) || ((abs(colNew - colOld) > 2) || (abs(rowNew - rowOld) > 2)) || (board[rowNew-65][colNew-49].side == RED))
    {
      cout << "Invalid piece move " << rowOld << colOld << " to " << rowNew << colNew << ". Try again...\n";
      continue;
    }
    rowNew = rowNew - 65;
    rowOld = rowOld - 65;
    colNew = colNew - 49;
    colOld = colOld - 49;
    endGame = updateBoard(board, colOld, rowOld, colNew, rowNew, endGame, SIZE);
    if (endGame == true)
    {
      updateBoard(board, colOld, rowOld, colNew, rowNew, endGame, SIZE);
      cout << "You win! Congratulations!\n";
    }
  }
  for (int i = 0; i < SIZE; i++)
  {
    delete [] board[i];
  }
  delete [] board;
  return 0;
}
