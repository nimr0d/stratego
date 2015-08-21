#ifndef _H_TEST_BOARD
#define _H_TEST_BOARD

#include <iostream>
using std::cout;
using std::endl;


#include "../src/Board.hpp"
#include "../src/Piece.hpp"


bool test_out_of_bounds(){
  bool all_cases_pass = true;
  all_cases_pass &= !out_of_bounds(0,0);
  all_cases_pass &= !out_of_bounds(5,2);
  all_cases_pass &= out_of_bounds(3,-1);
  all_cases_pass &= out_of_bounds(-1,3);
  all_cases_pass &= out_of_bounds(-1,-1);
  all_cases_pass &= out_of_bounds(2,10);
  all_cases_pass &= out_of_bounds(20,10);
  return all_cases_pass; 
}

bool test_get_position_moved(){
  int n_row, n_col;
  int row, col;
  bool all_cases_pass = true;
  Direction m;
  
  m = UP;
  row = 2; col = 2;
  get_position_moved(m, row, col, 
		     &n_row, &n_col);
  all_cases_pass &= ((n_row ==  1) && (n_col == 2));
  
  m = DOWN;
  row = 2; col = 2;
  get_position_moved(m, row, col, 
		     &n_row, &n_col);
  all_cases_pass &= ((n_row ==  3) && (n_col == 2));

  m = LEFT;
  row = 2; col = 2;
  get_position_moved(m, row, col, 
		     &n_row, &n_col);
  all_cases_pass &= ((n_row ==  2) && (n_col == 1));

  m = RIGHT;
  row = 2; col = 2;
  get_position_moved(m, row, col, 
		     &n_row, &n_col);
  all_cases_pass &= ((n_row ==  2) && (n_col == 3));
  
  return all_cases_pass; 
}

bool test_is_player_allowed_to_move_piece(){
  Board b;
  b.print(0);
  b.set_piece(Piece(FLAG, 0), 2, 2);
  b.print(0);
}

void test_Board(){
  std::cout << "testing board" << std::endl;
  cout << "testing out of bounds: " << test_out_of_bounds() << endl;
  cout << "testing get position moved: " << test_get_position_moved() << endl;
  test_is_player_allowed_to_move_piece();
}

#endif 
