#ifndef _H_AIBOARD_
#define _H_AIBOARD_

#include <queue>
#include <vector>

#include "AIMove.hpp"
#include "Piece.hpp"

class AIBoard {
public:
  AIBoard();
  float evaluate(); // Evaluates board and returns value.

  Piece piece(char pos) const;
  void set_piece(Piece p, char pos);
  bool player() const;
  void set_player(bool player);
  
  bool is_move_allowed(Move m) const;
  AIBoard make_move(Move m) const;

  std::priority_queue<AIBoard> get_child_states() const;
  
  bool operator==(const AIBoard& other) const;
  bool operator<(const AIBoard& other) const;
  
private:
  Piece board_[10][10];
  std::vector<Move> moves_;
  bool player_;
  float eval_;
  static void find_all_moves(); // FIXME: Make not static
};

#endif
