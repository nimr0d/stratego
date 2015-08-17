#ifndef _H_TEST_PIECE
#define _H_TEST_PIECE

#include <iostream>

#include "../src/Piece.hpp"


bool test_two_pieces(Piece strong, Piece weak){
  return ((strong > weak) && (weak < strong));
}


void test_piece(){
  std::cout << "testing piece" << std::endl;
}

#endif 
