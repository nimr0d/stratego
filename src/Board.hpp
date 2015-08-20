#ifndef _H_BOARD_
#define _H_BOARD_

#include <queue>
#include <vector>

#include "Piece.hpp"
#include "Player.hpp"
#include "Move.hpp"

class Board {
public:
  Board();
  float evaluate(); // Evaluates board and returns value.
  void print(Player player) const;
  std::priority_queue<Board> get_child_states() const;
  
  bool is_player_allowed_to_move_piece(int row, int col) const;
  bool is_move_allowed(Move m, int row, int col) const;
  Board make_move(Move m) const;
  
  void put_piece(Piece p, char pos);
  void put_piece(Piece p, char row, char col);

  bool operator==(const Board& other) const;
  bool operator<(const Board& other) const;
private:
  Piece board_[10][10];
  std::vector<Move> moves;
  Player player_;
  float eval_;
};

bool out_of_bounds(int row, int col);
void get_position_moved(Move m, int row, int col, 
			int* new_row, int* new_col);
bool is_piece_allowed_to_move(Piece p);

#endif
