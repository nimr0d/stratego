#ifndef _H_STRATEGO_GAME
#define _H_STRATEGO_GAME


#include "Move.hpp"
#include "Player.hpp"
#include "Board.hpp"

class StrategoGame{
public:
  StrategoGame();
  void play_game();
  Move ask_player_to_make_move(bool p);
  void send_move_result_to_player(MoveResult move_result, bool p);
private:
  Board state_;
  Player *players_[2];
};


#endif
