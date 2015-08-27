#include "Board.hpp"

#include <unordered_map>
#include <iostream>

#include <stdio.h>
#include <assert.h>

#include "Piece.hpp"
#include "Move.hpp"
#include "MoveResult.hpp"

using std::endl;
using std::cout;

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))


Board::Board() : player_(0){}

Board::Board(const Board& b){
  for(int i = 0; i < 10; ++i){
    for(int j = 0; j < 10; ++j){
      board_[i][j] = b.piece(i, j);
    }
  }
  player_ = b.player();
}

Piece Board::piece(int row, int col) const{
  return board_[row][col];
}

void Board::set_piece(Piece p, int row, int col){
  board_[row][col] = p;
}
bool Board::player() const{
  return player_;
}

bool Board::player_allowed_to_move_piece(int row, int col) const{
  Piece tmp = board_[row][col];
  return in_bounds(row, col) && tmp.player() == player_ && !tmp.empty();
}

bool Board::is_scout_move_valid(Move m) const {
  if(m.row == m.n_row){
    int big_col = MAX(m.col, m.n_col);
    int small_col = MIN(m.col, m.n_col);
    for(int i = small_col + 1; i < big_col; ++i) {
      if(!board_[m.row][i].empty()) {
        return false; 
      }
    }
    return true;
  } else {
    int big_row = MAX(m.row, m.n_row);
    int small_row = MIN(m.row, m.n_row);
    for(int i = small_row + 1; i < big_row; ++i) {
      if(!board_[i][m.col].empty()) {
        return false; 
      }
    }
    return true;
  }
}

bool Board::is_move_allowed(Move m) const {
  if(board_[m.row][m.col].value() == SCOUT) {
    if(!is_scout_move_valid(m)) {
      return false;
    }
  }
  return player_allowed_to_move_piece(m.row, m.col) &&
        in_bounds(m.n_row, m.n_col) && board_[m.row][m.col].is_movable() &&
        m.is_valid(board_[m.row][m.col]) &&
        (board_[m.row][m.col].player() != board_[m.n_row][m.n_col].player() || board_[m.n_row][m.n_col].empty());
}

MoveResult Board::get_move_result(Move m) const{
  if(!is_move_allowed(m)){
    return MoveResult(false, false , false, 0);
  }
  Piece p1 = piece(m.row, m.col);
  Piece p2 = piece(m.n_row, m.n_col);
  if(p2.value() == FLAG){
    return MoveResult(true, true , true, FLAG);
  } 
  if(p1.defeats(p2)){
    return MoveResult(true, false, true, p2.value());
  } else {
    return MoveResult(true, false, false, p2.value());
  }
}

Board Board::make_move(Move m) const{
  Board n_b(*this);
  assert(is_move_allowed(m));

  
  Piece p1 = n_b.piece(m.row, m.col);
  Piece p2 = n_b.piece(m.n_row, m.n_col);
  if(p1.defeats(p2)){
    n_b.set_piece(Piece(EMPTY,player_), m.row, m.col);
    n_b.set_piece(p1, m.n_row, m.n_col);
  } else {
    n_b.set_piece(Piece(EMPTY,player_), m.row, m.col);
  }
  return n_b;  
}


void Board::print(bool player) const{
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


bool in_bounds(int row, int col){
  return 0 <= row && row < 10 && 0 <= col && col < 10;
}
