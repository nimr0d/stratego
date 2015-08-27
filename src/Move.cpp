#include "Move.hpp"

#include <stdlib.h>
#include <stdio.h>

#include "Piece.hpp"


Move::Move(int r, int c, int r_n, int c_n) : row(r), col(c), n_row(r_n), n_col(c_n) {}

bool Move::is_valid(Piece p) const {
  if(p.value() == SCOUT) {
    bool going_up_or_down = abs(n_row - row) >= 1 && (n_col == col);
    bool going_sideways = abs(n_col - col) >= 1 && (n_row == row);
    return going_up_or_down || going_sideways;
  } else {
    bool going_up_or_down = abs(n_row - row) == 1 && (n_col == col);
    bool going_sideways = abs(n_col - col) == 1 && (n_row == row);
    return going_up_or_down || going_sideways;
  }
}
