#ifndef _H_HUMAN_PLAYER_
#define _H_HUMAN_PLAYER_

#include "Player.hpp"

class HumanPlayer : public Player {
public:
  virtual Move get_move() override;
  virtual void send_results_of_move(MoveResult) override;
  virtual bool is_human();
  //  ~HumanPlayer();
};


#endif
