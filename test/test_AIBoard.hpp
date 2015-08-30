#ifndef _H_TEST_AIBOARD
#define _H_TEST_AIBOARD

#include <iostream>

#include "../src/AIBoard.hpp"

void test_AIBoard() {
	/*for (int i = 40; i < 70; ++i) {
	  AdjacentSquaresBB[i].print();
	  std::cout << "\n";
  }
  WaterAreasBB.print();*/

  AIBoard b;
  b.set_player(0);
  for (char s = 0; s < 100; ++s) {
  	b.set_piece(Piece(0, 0), s);
  }
  b.set_piece(Piece(SPY, 0), 1);
  b.set_piece(Piece(MINER, 0), 2);
  b.set_piece(Piece(MINER, 0), 3);
  b.set_piece(Piece(MINER, 0), 12);
  b.set_piece(Piece(MARSHAL, 0), 13);
  b.set_piece(Piece(MINER, 1), 83);
  b.set_piece(Piece(BOMB, 1), 81);
  b.set_piece(Piece(FLAG, 1), 82);
  b.update_bitboards();

  b.print();
  
  AIMove m;
  m.from = 12;
  m.to = 22;

  b.make_move(m);

  b.print();
}

#endif