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

  void put_piece(Piece p, int row, int col);
private:
  Piece board_[10][10];
  Player player_;
};

bool out_of_bounds(const int& row, const int& col);
void get_position_moved(Move m, const int& row, const int& col, 
			int* new_row, int* new_col);
bool is_piece_allowed_to_move(Piece p);

#endif
