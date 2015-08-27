#ifndef _H_AI_PLAYER_
#define _H_AI_PLAYER_

#include "Participent.hpp"

class AIPlayer : public Participent{
public:
  Move get_move();
  void send_results_of_move(MoveResult);
  ~AIPlayer();
};


#endif
