#ifndef _H_BOARD_
#define _H_BOARD_

#include <queue>
#include <vector>

#include "Piece.hpp"
#include "Player.hpp"
#include "Move.hpp"
#include "MoveResult.hpp"

class Board {
public:
  Board();
  Board(const Board& );
  void print(Player player) const;
  
  bool is_player_allowed_to_move_piece(int row, int col) const;
  bool is_move_allowed(Move m) const;
  
  Board      make_move(Move m)       const;
  MoveResult get_move_result(Move m) const;
  
  void  set_piece(Piece p, int row, int col);
  Piece get_piece(int row, int col) const;
  Player player() const;
  
  bool is_scout_move_valid(Move m) const;
private:
  Piece board_[10][10];
  Player player_;
};

bool out_of_bounds(int row, int col);

#endif
