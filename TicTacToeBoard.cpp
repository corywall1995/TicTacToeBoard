#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == X) {
    turn = O;
    return turn;
  } else {
    turn = X;
    return turn;
  }
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  Piece temp = getPiece(row, column);
  if(temp == Invalid) {
    return Invalid;
  } else if(temp == Blank) {
    board[row][column] = turn;
    Piece temp = turn;
    toggleTurn();
    return temp;
  } else {
    return board[row][column];
  }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if (row > 2 || row < 0 || column > 2 || column < 0) {
    return Invalid;
  } else {
    return board[row][column];
  }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  Piece temp = getPiece(0,0);
  
  if(temp == getPiece(0,1) && temp == getPiece(0,2) && temp != Blank) {
    return temp;
  } else if(temp == getPiece(1,1) && temp == getPiece(2,2) && temp != Blank) {
    return temp;
  } else if(temp == getPiece(1,0) && temp == getPiece(2,0) && temp != Blank) {
    return temp;
  } 
  
  temp = getPiece(1,0);
  if(temp == getPiece(1,1) && temp == getPiece(1,2) && temp != Blank) {
    return temp;
  }
  
  temp = getPiece(2,0);
  if(temp == getPiece(2,1) && temp == getPiece(2,2) && temp != Blank) {
    return temp;
  } else if(temp == getPiece(1,1) && temp == getPiece(0,2) && temp != Blank) {
    return temp;
  }
  
  temp = getPiece(0,1);
  if(temp == getPiece(1,1) && temp == getPiece(2,1) && temp != Blank) {
    return temp;
  }
  
  temp = getPiece(0,2);
  if(temp == getPiece(1,2) && temp == getPiece(2,2) && temp != Blank) {
    return temp;
  }
  
  int blankCount = 0;
  
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      if (board[i][j] == Blank)
        blankCount++;
        
  if(blankCount == 0) {
    return Blank;
  }
  
  
  return Invalid;
}
