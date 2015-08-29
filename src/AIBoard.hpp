#ifndef _H_AIBOARD_
#define _H_AIBOARD_

#include <queue>
#include <vector>

#include "AIMove.hpp"
#include "Bitboard.hpp"
#include "Piece.hpp"

class AIBoard {
public:
  AIBoard();
  float evaluate() const; // Evaluates board and returns value.

  Piece piece(char pos) const;
  void set_piece(Piece p, char pos);
  bool player() const;
  void set_player(bool player);
  
  bool is_move_allowed(Move m) const;
  void make_move(Move m); // Updates board state after move and changes player.

  std::priority_queue<AIBoard> get_child_states() const;
  
  bool operator==(const AIBoard& other) const;
  bool operator<(const AIBoard& other) const;
  
private:
  Piece board_[100];

  Bitboard bad_dest_[2]; // Player pieces and water areas.
  Bitboard movables_[2]; // Movable pieces for player.
  Bitboard potential_movables_; // All pieces of any player that are a movable type.
  std::vector<Move> moves_;
  bool player_;
  mutable float eval_;
  static void find_all_moves(); // FIXME: Make not static.
};

#endif
