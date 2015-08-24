#ifndef _H_MOVE_
#define _H_MOVE_

#include "Piece.hpp"



//typedef struct Move Move;
struct Move{
  Move(int,int,int,int);
  int row  , col;    // initial position
  int n_row, n_col; //  final position
  
  bool is_valid(Piece p) const;
};


#endif
