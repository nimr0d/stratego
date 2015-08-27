#ifndef _H_PLAYER_
#define _H_PLAYER_

#include "Move.hpp"
#include "MoveResult.hpp"

class Player{ 
public:
  virtual Move get_move();
  virtual void send_results_of_move(MoveResult);
};
#endif
