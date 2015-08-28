#ifndef _H_AI_PLAYER_
#define _H_AI_PLAYER_

#include "Player.hpp"

class AIPlayer : public Player {
public:
  virtual Move get_move();
  virtual void send_results_of_move(MoveResult);
  virtual bool is_human();
  //  ~AIPlayer();
};


#endif
