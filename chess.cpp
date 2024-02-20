// #include "grader.h"
#include <iostream>
using namespace std;


class chessboard
{
public:
  enum piece
  { Rook, Knight, Bishop, Queen, King, Pawn };

public:
  enum color
  { Black, White };

public:
    piece ** board;
public:
  int size;
    chessboard (int size)
  {
    this->size = size;
    board = new piece *[size];
    for (int i = 0; i < size; i++)
      {
  board[i] = new piece[size];
      }
  }
   ~chessboard ()
  {
    for (int i = 0; i < size; i++)
      {
  delete[]board[i];
      }
    delete[]board;
  }
  int place (int x, int y, char color, piece p)
  {
    if (x < 0 || x > size || y < 0 || y > size)
      {
  return -1;
      }
    if (color != Black && color != White)
      {
  return -4;
      }
    if (p != Rook && p != King && p != Bishop && p != Queen
  && p != Pawn && p != Knight)
      {
  return -5;
      }
    if (board[x][y] != ' ')
      {
  return -3;
      }
    board[x][y] = p;
    return 1;
  }
  int get (int x, int y, char &color, piece & p)
  {
    if (x < 0 || x > size || y < 0 || y > size)
      {
  return -1;
      }
    if (board[x][y] == ' ')
      {
  return -3;
      }
    p = board[x][y];
    color = color;
    return 1;
  }
};

struct iterator
{
  int x;
  int y;
  chessboard *board;
    iterator (chessboard * board)
  {
    this->board = board;
    x = 0;
    y = 0;
  }
  void next ()
  {
    if (y == board->size - 1)
      {
  x++;
  y = 0;
      }
    else
      {
  y++;
      }
  }
  void xy (int &x, int &y)
  {
    x = this->x;
    y = this->y;
  }
};

