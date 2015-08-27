#ifndef _H_TEST_BOARD
#define _H_TEST_BOARD

#include <iostream>

#include <stdlib.h>
#include <time.h>

#include "../src/Board.hpp"
#include "../src/Piece.hpp"

using std::cout;
using std::endl;


bool test_out_of_bounds(){
  bool all_cases_pass = true;
  all_cases_pass &= in_bounds(0,0);
  all_cases_pass &= in_bounds(5,2);
  all_cases_pass &= !in_bounds(3,-1);
  all_cases_pass &= !in_bounds(-1,3);
  all_cases_pass &= !in_bounds(-1,-1);
  all_cases_pass &= !in_bounds(2,10);
  all_cases_pass &= !in_bounds(20,10);
  return all_cases_pass; 
}

bool test_set_get_piece(){
  Board b;
  bool all_get_set_works = true;
  for(int i = 0; i < 10; i++){
    Piece p = Piece(rand() % 12, 0);
    int row = rand() % 10;
    int col = rand() % 10;
    b.set_piece(p, row, col);
    all_get_set_works &= (b.piece(row,col) == p);
  }
  return all_get_set_works;
}

bool test_is_move_allowed(){
  Board b;
  b.set_piece(Piece(6,0), 2, 2);
  b.set_piece(Piece(6,0), 2, 3);
  b.set_piece(Piece(6,1), 2, 4);
  b.set_piece(Piece(6,0), 3, 4);
  b.set_piece(Piece(SCOUT,0), 4, 4);
  //b.print(0);
  
  bool all_is_valid = true;
  
  all_is_valid &= b.is_move_allowed( Move(2,2, 3,2));
  all_is_valid &= !b.is_move_allowed(Move(2,2, 3,3));
  all_is_valid &= b.is_move_allowed( Move(2,2, 2,1));
  all_is_valid &= b.is_move_allowed( Move(2,2, 2,1));
  all_is_valid &= !b.is_move_allowed(Move(2,1, 2,2));
  all_is_valid &= !b.is_move_allowed(Move(2,2, 2,2));
  all_is_valid &= !b.is_move_allowed(Move(2,3, 2,2));
  all_is_valid &= b.is_move_allowed( Move(2,3, 2,4));
  all_is_valid &= b.is_move_allowed( Move(4,4, 4,9));
  all_is_valid &= !b.is_move_allowed( Move(4,4, 0,4));
  
  return all_is_valid;
}

bool test_make_move(){
  Board b;
  bool all_is_valid = true;
  b.set_piece(Piece(6,0), 2, 2);
  b = b.make_move(Move(2,2,3,2));
  b = b.make_move(Move(3,2,3,3));
  all_is_valid = (Piece(6,0) == b.piece(3,3));
  
  b.set_piece(Piece(5,1), 3,4);
  b = b.make_move(Move(3,3,3,4));
  b.print(0);
  return all_is_valid;
}

bool test_make_move_result(){
  
}


void test_Board(){
  std::cout << "testing board" << std::endl;
  cout << "testing out of bounds: " << test_out_of_bounds() << endl;
  cout << "testing get_set: " << test_set_get_piece() << endl;
  cout << "testing is_move_allowed: " << test_is_move_allowed() << endl;
  cout << "testing make move: " << test_make_move() << endl;
}

#endif 
