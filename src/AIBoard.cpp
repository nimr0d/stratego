#include "AIBoard.hpp"

#include <assert.h>
#include <stdio.h>

AIBoard::AIBoard() : player_(0){}

float AIBoard::evaluate() {
  // TODO: evaluation code
  eval_ = 0;
  return eval_;
}

Piece AIBoard::piece(char pos) const {
  return ((Piece *) board_)[pos]; 
}

void AIBoard::set_piece(Piece p, char pos) {
  ((Piece *) board_)[pos] = p; 
}

Player AIBoard::player() const{
  return player_;
}

void AIBoard::set_player(Player player) {
  player_ = player;
}

bool AIBoard::is_move_allowed(Move m) const{
  Piece p1 = piece(m.from);
  Piece p2 = piece(m.to);
  return m.to < 100 && m.from < 100 && p1.player() == player_ && p1.is_movable() && (p2.empty() || p2.player() == !player_);
}

AIBoard AIBoard::make_move(Move m) const{
  assert(is_move_allowed(m));
  AIBoard n_b(*this);
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

std::priority_queue<AIBoard> AIBoard::get_child_states() const {
  // TODO: logic to replace find_all_moves() with something smarter
  std::priority_queue<AIBoard> pq;
  find_all_moves();
  for (Move m : moves_) {
    AIBoard b = make_move(m);
    b.evaluate();
    pq.push(b);
  }
  return pq;
}

bool AIBoard::operator==(const AIBoard& other) const {
  return eval_ == other.eval_;
}

bool AIBoard::operator<(const AIBoard& other) const {
  return eval_ < other.eval_;
}

void AIBoard::find_all_moves() {
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      // TODO: add all moves
    }
  }
}

bool out_of_bounds(int row, int col){
  return !(0 <= row && row < 10 && 0 <= col && col < 10);
}
