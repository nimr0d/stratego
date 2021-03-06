#ifndef _H_TEST_PIECE
#define _H_TEST_PIECE

#include <iostream>
#include <stdio.h>

#include "../src/Piece.hpp"


bool test_two_pieces(Piece strong, Piece weak){
  bool r = strong.defeats(weak);
  if (!r) {
    printf("%c defeats %c fails \n", strong.symbol(), weak.symbol());
  }
  return r;
}


void test_piece(){
  printf("testing piece \n");
  printf("test case: %d \n", test_two_pieces(Piece(2, 0) , Piece(1, 0) ));
  printf("test case: %d \n", test_two_pieces(Piece(12, 0) ,Piece(6, 0) ));
  printf("test case: %d \n", test_two_pieces(Piece(4, 0) ,Piece(12, 0) ));
  printf("test case: %d \n", test_two_pieces(Piece(11, 0) ,Piece(3, 0) ));
  printf("test case: %d \n", test_two_pieces(Piece(2, 0) ,Piece(11, 0) ));
  printf("test case: %d \n", test_two_pieces(Piece(11, 0) ,Piece(10, 0) ));
}

#endif 
