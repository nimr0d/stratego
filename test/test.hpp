#ifndef _H_TEST
#define _H_TEST

#include "test_piece.hpp"
#include "test_Board.hpp"
//#include "test_BoardIO.hpp"

#include <stdlib.h>
#include <time.h>


void test(){
  srand(time(NULL));
  test_piece();
  test_Board();
}

#endif 
