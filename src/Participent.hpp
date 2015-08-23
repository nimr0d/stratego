#ifndef _H_PARTICIPENT_
#define _H_PARTICIPENT_

/*This file is pretty much bullshit, 
  it should be player, fuck player, Player should be renamed: PlayerTurn!!
  and Participent should be renamed Player
*/

// This should be an "Java-Interface" like class,
// All of the methods are purely virtual.

#include "Move.hpp"
#include "MoveResult.hpp"

class Participent{ 
public:
  virtual Move get_move();
  virtual void send_results_of_move(MoveResult);
  virtual ~Participent();
};


#endif



