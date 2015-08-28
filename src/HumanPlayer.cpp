#include "HumanPlayer.hpp"

#include <iostream>

#include "Move.hpp"
#include "MoveResult.hpp"

using std::cout;
using std::cin;
using std::endl;


Move HumanPlayer::get_move() {
  cout << "What your move?" << 
    "Enter in the following format (row_from col_from row_to col_to)" << endl;
  int row,col, n_row, n_col;
  cin >> row;
  cin >> col;
  cin >> n_row;
  cin >> n_col;
}

void HumanPlayer::send_results_of_move(MoveResult move_result) {
  move_result.print();
}


/*
HumanPlayer::~HumanPlayer(){
  cout<< "destroying humanPlayer" << endl;
}*/

