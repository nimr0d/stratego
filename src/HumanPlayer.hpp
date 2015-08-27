#ifndef _H_HUMAN_PLAYER_
#define _H_HUMAN_PLAYER_

#include "Player.hpp"

class HumanPlayer : public Player {
public:
  Move get_move();
  void send_results_of_move(MoveResult);
  //  ~HumanPlayer();
};


#endif
