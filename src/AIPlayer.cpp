#include "AIPlayer.hpp"

#include <iostream>


#include "Move.hpp"


using std::cout;
using std::cin;
using std::endl;

Move AIPlayer::get_move() {
  cout << "What your move?" << 
    "Enter in the following format (row_from col_from row_to col_to)" << endl;
  int row,col, n_row, n_col;
  cin >> row;
  cin >> col;
  cin >> n_row;
  cin >> n_col;
  return Move(row,col, n_row, n_col);
}

void AIPlayer::send_results_of_move(MoveResult move_result) {
  move_result.print();
}


bool AIPlayer::is_human(){
  return false;
}
