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
  b.set_piece(Piece(8, 0), 0);
  b.set_piece(Piece(MINER, 0), 1);
  b.set_piece(Piece(MINER, 0), 2);
  b.set_piece(Piece(MINER, 0), 3);
  b.set_piece(Piece(5, 0), 4);
  b.set_piece(Piece(BOMB, 0), 5);
  b.set_piece(Piece(FLAG, 0), 6);
  b.set_piece(Piece(BOMB, 0), 7);
  b.set_piece(Piece(BOMB, 0), 8);
  b.set_piece(Piece(MINER, 0), 9);
  b.set_piece(Piece(8, 0), 10);
  b.set_piece(Piece(SCOUT, 0), 11);
  b.set_piece(Piece(8, 0), 12);
  b.set_piece(Piece(SPY, 0), 13);
  b.set_piece(Piece(7, 0), 14);
  b.set_piece(Piece(6, 0), 15);
  b.set_piece(Piece(BOMB, 0), 16);
  b.set_piece(Piece(5, 0), 17);
  b.set_piece(Piece(6, 0), 18);
  b.set_piece(Piece(SCOUT, 0), 19);
  b.set_piece(Piece(5, 0), 20);
  b.set_piece(Piece(SCOUT, 0), 21);
  b.set_piece(Piece(9, 0), 22);
  b.set_piece(Piece(9, 0), 23);
  b.set_piece(Piece(10, 0), 24);
  b.set_piece(Piece(SCOUT, 0), 25);
  b.set_piece(Piece(5, 0), 26);
  b.set_piece(Piece(BOMB, 0), 27);
  b.set_piece(Piece(BOMB, 0), 28);
  b.set_piece(Piece(6, 0), 29);
  b.set_piece(Piece(MARSHAL, 0), 30);
  b.set_piece(Piece(7, 0), 31);
  b.set_piece(Piece(6, 0), 32);
  b.set_piece(Piece(MINER, 0), 33);
  b.set_piece(Piece(SCOUT, 0), 34);
  b.set_piece(Piece(7, 0), 35);
  b.set_piece(Piece(SCOUT, 0), 36);
  b.set_piece(Piece(SCOUT, 0), 37);
  b.set_piece(Piece(SCOUT, 0), 38);
  b.set_piece(Piece(7, 0), 39);

  b.set_piece(Piece(7, 1), 60);
  b.set_piece(Piece(SCOUT, 1), 61);
  b.set_piece(Piece(MARSHAL, 1), 62);
  b.set_piece(Piece(MINER, 1), 63);
  b.set_piece(Piece(SPY, 1), 64);
  b.set_piece(Piece(SCOUT, 1), 65);
  b.set_piece(Piece(6, 1), 66);
  b.set_piece(Piece(SCOUT, 1), 67);
  b.set_piece(Piece(SCOUT, 1), 68);
  b.set_piece(Piece(7, 1), 69);
  b.set_piece(Piece(SCOUT, 1), 70);
  b.set_piece(Piece(9, 1), 71);
  b.set_piece(Piece(8, 1), 72);
  b.set_piece(Piece(8, 1), 73);
  b.set_piece(Piece(SCOUT, 1), 74);
  b.set_piece(Piece(10, 1), 75);
  b.set_piece(Piece(SPY, 1), 76);
  b.set_piece(Piece(BOMB, 1), 77);
  b.set_piece(Piece(5, 1), 78);
  b.set_piece(Piece(6, 1), 79);
  b.set_piece(Piece(5, 1), 80);
  b.set_piece(Piece(7, 1), 81);
  b.set_piece(Piece(6, 1), 82);
  b.set_piece(Piece(BOMB, 1), 83);
  b.set_piece(Piece(6, 1), 84);
  b.set_piece(Piece(9, 1), 85);
  b.set_piece(Piece(8, 1), 86);
  b.set_piece(Piece(5, 1), 87);
  b.set_piece(Piece(BOMB, 1), 88);
  b.set_piece(Piece(5, 1), 89);
  b.set_piece(Piece(MINER, 1), 90);
  b.set_piece(Piece(MINER, 1), 91);
  b.set_piece(Piece(BOMB, 1), 92);
  b.set_piece(Piece(FLAG, 1), 93);
  b.set_piece(Piece(BOMB, 1), 94);
  b.set_piece(Piece(MINER, 1), 95);
  b.set_piece(Piece(SCOUT, 1), 96);
  b.set_piece(Piece(BOMB, 1), 97);
  b.set_piece(Piece(MINER, 1), 98);
  b.set_piece(Piece(SCOUT, 1), 99);

  b.update_bitboards();

  b.print();

  b.get_children();
}

#endif