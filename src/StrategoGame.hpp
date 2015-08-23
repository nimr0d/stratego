#ifndef _H_STRATEGO_GAME
#define _H_STRATEGO_GAME


#include "Move.hpp"
#include "Player.hpp"
#include "Participent.hpp"


class StrategoGame{
public:
  StrategoGame();
  void play_game();
  Move        ask_participent_to_move();
  void        send_move_results_to_participent(MoveResult move_result, Player p);
private:
  Board _state;
  Participent participents_[2];
};


#endif
