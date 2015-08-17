#include "Piece.hpp"

bool operator<(const Piece& p_left, const Piece& p_right){
  if(!p_right.is_special() && !p_right.is_special()){
    return p_right.get_type() < p_right.get_type();
  }
}

