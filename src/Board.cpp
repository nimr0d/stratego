#include "Board.hpp"

#include <unordered_map>

#include <stdio.h>
#include <assert.h>

#include "Piece.hpp"
#include "Move.hpp"

Board::Board() : player_(0){}
Board::Board(const Board& b){
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      board_[i][j] = b.get_piece(i, j);
    }
  }
  player_ = b.player();
}


void Board::set_piece(Piece p, int row, int col){
  board_[row][col] = p;
}

Piece Board::get_piece(int row, int col) const{
  return board_[row][col];
}

Player Board::player() const{
  return player_;
}
bool out_of_bounds(int row, int col){
  return !(0 <= row && row < 10 && 0 <= col && col < 10);
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

bool Board::is_move_allowed(Move m) const{
  if(!is_player_allowed_to_move_piece(m.row, m.col))
    return false;
  
  if(out_of_bounds(m.n_row, m.n_col) ){
    return false;
  }
  
  if(!is_piece_allowed_to_move(board_[m.row][m.col])){
    return false;
  }
  
  if(!m.is_valid(board_[m.row][m.col])){
    return false;
  }
  /*should we check if the space is occupied by another piece
    of the same player?*/
  return true;
}


Board Board::make_move(Move m) const{
  Board new_B(*this);
  assert(is_move_allowed(m) );

  
  Piece p1 = new_B.get_piece(m.row, m.col);
  Piece p2 = new_B.get_piece(m.n_row, m.n_col);
  if(p1.defeats(p2)){
    new_B.set_piece(Piece(EMPTY,player_), m.row, m.col);
    new_B.set_piece(p1, m.n_row, m.n_col);
  } else {
    new_B.set_piece(Piece(EMPTY,player_), m.row, m.col);
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
