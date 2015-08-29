#ifndef _H_TEST_BOARDIO
#define _H_TEST_BOARDIO

#include <iostream>
using std::cout;
using std::endl;


#include "../src/Board.hpp"
#include "../src/BoardIO.hpp"
#include "../src/Piece.hpp"
#include "../src/BoardFactory.hpp"


void test_BoardIO(){
  cout << "testing BoardIO" << endl;
  Board b = board_factory_1();
  write_board_to_file("test1.txt" , b);
  b = read_board_from_file("test1.txt");
  b.print(0);
}

#endif 
