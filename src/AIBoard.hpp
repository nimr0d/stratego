#ifndef _H_AIBOARD_
#define _H_AIBOARD_

#include "AIMove.hpp"
#include "Bitboard.hpp"
#include "Piece.hpp"
#include <stdio.h>

class AIBoard {
public:
  AIBoard();
  float evaluate(); // Evaluates board and returns value.

  Piece piece(char pos) const;
  void set_piece(Piece p, char pos);
  bool player() const;
  void set_player(bool player);
  void update_bitboards(); // Probably only used for init. Might rename init_bitboards.
  
  void make_move(AIMove m); // Updates board state after move and changes player.
  
  // Temporary -- just for testing a few things.
  void print() {
    for(int i = 9; i >= 0; --i){
      for(int j = 0; j < 10; ++j){
        Piece tmp = board_[10 * i + j];
          if(tmp.empty()){
            printf(".");
          }
          else {
            printf("%c", tmp.symbol());
          }
          printf(" ");
        }
       printf("\n");
     }
    printf("\n");

    for (int i = 0; i < 2; ++i) {
      bad_dest_[i].print();
      printf("\n");
      movables_[i].print();
      printf("\n");
    }
    potential_movables_.print();
  }
private:
  Piece board_[100];

  Bitboard bad_dest_[2]; // Player pieces and water areas.
  Bitboard movables_[2]; // Movable pieces for player.
  Bitboard potential_movables_; // All pieces of any player that are a movable type.
  bool player_;
  static void find_all_moves(); // FIXME: Make not static.
};

#endif
