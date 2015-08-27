#ifndef _H_AI_PLAYER_
#define _H_AI_PLAYER_

#include "Player.hpp"

class AIPlayer : public Player {
public:
  Move get_move();
  void send_results_of_move(MoveResult);
  ~AIPlayer();
};


#endif
