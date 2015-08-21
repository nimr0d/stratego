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

  Piece piece(char pos) const;
  Piece piece(int row, int col) const;
  void  set_piece(Piece p, char pos);
  void  set_piece(Piece p, int row, int col);
  
  bool is_player_allowed_to_move_piece(int row, int col) const;
  bool is_move_allowed(Direction m, int row, int col) const;
  bool is_move_allowed(Move m) const;
  Board make_move(Move m) const;

  std::priority_queue<Board> get_child_states() const;
  
  bool operator==(const Board& other) const;
  bool operator<(const Board& other) const;

  void print(Player player) const;
  
private:
  Piece board_[10][10];
  std::vector<Move> moves_;
  Player player_;
  float eval_;
  static void find_all_moves();
};

bool out_of_bounds(int row, int col);
void get_position_moved(Direction m, int row, int col,
			int* new_row, int* new_col);
bool is_movable(Piece p);

#endif
