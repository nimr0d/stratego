#include "Piece.hpp"

bool Piece::operator==(const Piece& p_left, const Piece& p_right) {
  return p_left.value() == p_right.value();
}

bool Piece::operator<(const Piece& p_left, const Piece& p_right){
  if (p_right.value() == BOMB && p_left.value() == MINER) return false;
  if (p_right.value() == SPY && p_left.value() == MARSHAL) return false;
  return p_left.value() < p_right.value();
}

