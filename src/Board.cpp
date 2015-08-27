#include "Board.hpp"

#include <unordered_map>

#include <stdio.h>
#include <assert.h>

#include "Piece.hpp"
#include "Move.hpp"
#include "MoveResult.hpp"

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
Player Board::player() const{
  return player_;
}

bool Board::player_allowed_to_move_piece(int row, int col) const{
  Piece tmp = board_[row][col];
  return in_bounds(row, col) && tmp.player() == player_ && !tmp.empty();
}


bool Board::is_move_allowed(Move m) const {
  return player_allowed_to_move_piece(m.row, m.col) &&
        in_bounds(m.n_row, m.n_col) && board_[m.row][m.col].is_movable() &&
        m.is_valid(board_[m.row][m.col]) &&
        board_[m.row][m.col].player() != board_[m.n_row][m.n_col].player();
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


bool in_bounds(int row, int col){
  return 0 <= row && row < 10 && 0 <= col && col < 10;
}
