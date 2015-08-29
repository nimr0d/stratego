#ifndef _H_PLAYER_
#define _H_PLAYER_

#include "Move.hpp"
#include "MoveResult.hpp"

class Player { 
public:
  virtual Move get_move() = 0;
  virtual void send_results_of_move(MoveResult) = 0;
  virtual bool is_human() = 0;
};
#endif
