#include "Board.hpp"

#include <unordered_map>

#include <stdio.h>
#include <assert.h>

#include "Piece.hpp"
#include "Move.hpp"

Board::Board() : player_(0), eval_(0) {}




float Board::evaluate() {
  // TODO: evaluation code
  eval_ = 0;
  return eval_;
}

void Board::set_piece(Piece p, int row, int col){
  board_[row][col] = p;
}

Piece Board::get_piece(int row, int col) const{
  return board_[row][col];
}

bool Board::operator==(const Board& other) const {
  return eval_ == other.eval_;
}

bool Board::operator<(const Board& other) const {
  return eval_ < other.eval_;
}

bool out_of_bounds(int row, int col){
  return 0 <= row && row < 10 && 0 <= col && col < 10;
}

void get_position_moved(Move m, int row, int col, 
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

bool Board::is_player_allowed_to_move_piece(int row,int col) const{
  if(out_of_bounds(row, col))
    return false;
  Piece tmp = board_[row][col];
  if(tmp.player() != player_)
    return false;
  if(tmp.empty())
    return false;
  return true;
}

bool is_piece_allowed_to_move(Piece p){
  return !(p.value() == BOMB || p.value() == FLAG);
}

bool Board::is_move_allowed(Move m, int row, int col) const{
  if(!is_player_allowed_to_move_piece(row, col))
    return false;
  
  int new_row, new_col;
  get_position_moved(m, row, col, &new_row, &new_col);
  if(out_of_bounds(new_row, new_col) ){
    return false;
  }
  
  is_piece_allowed_to_move(board_[row][col]);
  /*should we check if the space is occupied by another piece
    of the same player*/
  return true;
}


Board Board::make_move(Move m, int row, int col) const{
  Board new_B(*this);
  assert(is_move_allowed(m, row, col) );

  int n_row, n_col;
  get_position_moved(m, row, col, &n_row, &n_col);
  Piece p1 = new_B.get_piece(row, col);
  Piece p2 = new_B.get_piece(n_row, n_col);
  if(p1.defeats(p2)){
    new_B.set_piece(Piece(EMPTY,player_), row, col);
    new_B.set_piece(p1, n_row, n_col);
  } else {
    new_B.set_piece(Piece(EMPTY,player_), row, col);
  }
  return new_B;  
}


void Board::print(Player player) const{
  for(int i = 0; i < 10; ++i){
    printf("__");
  }
  printf("\n");
  for(int i = 0; i < 10; ++i){
    for(int j = 0; j < 10; ++j){
      const Piece *tmp = &board_[i][j];
      if(tmp->empty()){
	printf(".");
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
  for(int i = 0; i < 10; ++i){
    printf("__");
  }
  printf("\n");
}
