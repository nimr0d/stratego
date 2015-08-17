#ifndef _H_BOARD_CPP
#define _H_BOARD_CPP

#include <vector>

#include "Piece.hpp"
#include "Player.hpp"
#include "Move.hpp"

class Board{
public:
  Board();
  float eval();
  void print(Player) const;
  
  std::vector<Board> get_child_states();
  
private:
  Board make_move(Move m);
  Piece board[10][10];
  Player player;
};

#endif
