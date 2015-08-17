#ifndef _H_BOARD_
#define _H_BOARD_

#include <vector>

#include "Piece.hpp"
#include "Move.hpp"

class Board{
public:
  Board();
  float eval() const;
  void print(bool player) const;
  
  std::vector<Board> get_child_states();
  
private:
  Board make_move(Move m);
  Piece board_[10][10];
  bool player_;
};

#endif
