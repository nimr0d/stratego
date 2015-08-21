#include "Board.hpp"

#include <unordered_map>
#include <stdio.h>

#include "Piece.hpp"
#include "Move.hpp"

Board::Board() : player_(0), eval_(0) {}

float Board::evaluate() {
  // TODO: evaluation code
  eval_ = 0;
  return eval_;
}

void Board::put_piece(Piece p, char pos) {
  ((Piece *) board_)[pos] = p; 
}
void Board::put_piece(Piece p, char row, char col){
  board_[row][col] = p;
}

void Board::find_all_moves() {
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      // TODO: add all moves
    }
  }
}

Board Board::make_move(Move m) const {
  // TODO: make move
  return Board(); // temporary
}

std::priority_queue<Board> Board::get_child_states() const {
  // TODO: logic to replace find_all_moves() with something smarter
  std::priority_queue<Board> pq;
  find_all_moves();
  for (Move m : moves_) {
    Board b = make_move(m);
    b.evaluate();
    pq.push(b);
  }
  return pq;
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

void get_position_moved(Direction m, int row, int col, 
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


bool Board::is_move_allowed(Direction m, int row, int col) const{
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
