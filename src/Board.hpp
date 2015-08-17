#ifndef _H_BOARD_CPP
#define _H_BOARD_CPP

#include <vector>

class Board{
public:
  Board();
  float eval();
  void print() const;
  
  std::vector<Board> get_child_states();
  
private:
  Board make_move(Move m);
  Pieces board[10][10];
  Player player;
};

#endif
