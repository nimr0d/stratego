#ifndef _H_HUMAN_PLAYER_
#define _H_HUMAN_PLAYER_

#include "Participent.hpp"

class HumanPlayer : public Participent{
public:
  Move get_move();
  void send_results_of_move(MoveResult);
  ~HumanPlayer();
};


#endif
