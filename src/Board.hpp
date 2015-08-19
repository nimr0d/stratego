#ifndef _H_BOARD_
#define _H_BOARD_

#include <vector>

#include "Piece.hpp"
#include "Player.hpp"
#include "Move.hpp"

class Board{
public:
  Board();
  float eval() const;
  void print(Player player) const;
  
  std::vector<Board> get_child_states() const;
  
  bool is_player_allowed_to_move_piece(const int& row,const int& col) const;
  bool is_move_allowed(Move m, int row, int col) const;
  Board make_move(Move m) const;
private:
  Piece board_[10][10];
  Player player_;
};

#endif
