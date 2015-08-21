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

Piece Board::piece(char pos) const {
  return ((Piece *) board_)[pos]; 
}

Piece Board::piece(int row, int col) const{
  return board_[row][col];
}

void Board::set_piece(Piece p, char pos) {
  ((Piece *) board_)[pos] = p; 
}

void Board::set_piece(Piece p, int row, int col){
  board_[row][col] = p;
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

bool Board::is_move_allowed(Direction m, int row, int col) const{
  if(!is_player_allowed_to_move_piece(row, col))
    return false;
  
  int new_row, new_col;
  get_position_moved(m, row, col, &new_row, &new_col);
  if(out_of_bounds(new_row, new_col) ){
    return false;
  }
  
  is_movable(board_[row][col]);
  /*should we check if the space is occupied by another piece
    of the same player*/
  return true;
}


bool Board::is_move_allowed(Move m) const{
  Piece p1 = piece(m.from);
  Piece p2 = piece(m.from);
  return m.to < 100 && m.from < 100 && p1.player() == player_ && is_movable(tmp) && (p2.empty() || p2.player() == !player_);
}

Board Board::make_move(Move m) const{
  assert(is_move_allowed(m));
  Board n_b(*this);
  Piece p1 = n_b.piece(m.from);
  Piece p2 = n_b.piece(m.to);
  if(p1.defeats(p2)){
    n_b.set_piece(Piece(EMPTY, player_), m.from);
    n_b.set_piece(p1, m.to);
  } else {
    n_b.set_piece(Piece(EMPTY,player_), m.from);
  }
  return n_b;  
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

void Board::find_all_moves() {
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      // TODO: add all moves
    }
  }
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

bool is_movable(Piece p){
  return !(p.value() == BOMB || p.value() == FLAG || p.value() == EMPTY);
}
