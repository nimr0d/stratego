#include "Move.hpp"

#include <stdlib.h>
#include <stdio.h>

#include "Piece.hpp"


bool Move::is_valid(Piece p) const{
  if(p.value() == SCOUT){
    bool going_up_or_down = abs(n_row - row) >= 1 && (n_col == col);
    bool going_sideways   = abs(n_col - col) >= 1 && (n_row == row);
    return going_up_or_down || going_sideways;
  } else {
    bool going_up_or_down = abs(n_row - row) == 1 && (n_col == col);
    bool going_sideways   = abs(n_col - col) == 1 && (n_row == row);
    return going_up_or_down || going_sideways;
  }
}
