#include "Board.hpp"

#include <unordered_map>

#include <stdio.h>

#include "Piece.hpp"
#include "Move.hpp"

Board::Board() {}

bool out_of_bounds(const int& row, const int& col){
  if     (row >= 10 || row < 0)
    return true;
  else if(col >= 10 || col < 0)
    return true;
  else 
    return false;
}

void get_position_moved(Move m, const int& row, const int& col, 
			int* new_row, int* new_col){
  switch(m){
  case UP:
    *new_row = row - 1;
    *new_col = col;
    break;
  case DOWN:
    *new_row = row + 1;
    *new_col = col;
    break;
  case LEFT:
    *new_row = row;
    *new_col = col - 1;
    break;
  case RIGHT:
    *new_row = row;
    *new_col = col + 1;
    break;
  }
}

bool Board::is_player_allowed_to_move_piece(const int& row,const int& col) const{
  if(out_of_bounds(row, col))
    return false;
  Piece tmp = board_[row][col];
  if(tmp.player() != player_)
    return false;
  if(tmp.empty())
    return false;
  return true;
}

bool Board::is_move_allowed(Move m, int row, int col) const{
  if(!is_player_allowed_to_move_piece(row, col))
    return false;
  
  int new_row, new_col;
  get_position_moved(m, row, col, &new_row, &new_col);
  if( out_of_bounds(new_row, new_col) ){
    return false;
  }
  /*should we check if the space is occupied by another piece of the same player*/
  return true;
}


void Board::print(Player player) const{
  for(int i = 0; i < 10; ++i){
    for(int j = 0; j < 10; ++j){
      const Piece *tmp = &board_[i][j];
      if(tmp->empty()){
	printf(" ");
      }
      else{
	if(tmp->player() == player){
	  printf("%c", tmp->symbol());
	} else{
	  printf("?");
	}
      }
      printf(" ");
    }
    printf("\n");
  }
  printf("\n");
}
