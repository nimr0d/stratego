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

bool AIBoard::player() const {
  return player_;
}

void AIBoard::set_player(bool player) {
  player_ = player;
}

bool AIBoard::is_move_allowed(Move m) const {
  Piece p1 = piece(m.from);
  Piece p2 = piece(m.to);
  return m.to < 100 && m.from < 100 && p1.player() == player_ && p1.is_movable() && (p2.empty() || p2.player() == !player_);
}

void AIBoard::make_move(Move m) {
  Piece p1 = piece(m.from);
  Piece p2 = piece(m.to);
  if(p1.defeats(p2)) {
    set_piece(Piece(EMPTY, player_), m.from);
    set_piece(p1, m.to);

    bad_dest_[player_] |= SquareBB[m.to]; // Player changed in m.to.
    bad_dest_[!player_] ^= SquareBB[m.to];

    potential_movables_ |= SquareBB[m.to]; // Movable piece moved into m.to.
    //Pieces around m.to which are the other player's are now movable.

    Bitboard b = AdjacentSquaresBB[m.to] & bad_dest_[player_] & potential_movables_;
    for (char s = (m.to > 9 ? m.to - 10 : 0); s <= m.to + 10; ++s) {
      if (bool(b & SquareBB[s]) && (AdjacentSquaresBB[s] & bad_dest_[player_]) == bad_dest_[player_]) {
        movables_[player_] |= SquareBB[s];
      }
    }

    movables_[!player_] |= AdjacentSquaresBB[m.to] & bad_dest_[!player_] & potential_movables_;
  } else {
    set_piece(Piece(EMPTY,player_), m.from);
  }
  // m.from is now empty.
  bad_dest_[player_] ^= SquareBB[m.from];
  movables_[player_] ^= SquareBB[m.from];
  potential_movables_ ^= SquareBB[m.from];

  // Pieces around m.from are now movable.
  movables_[0] |= AdjacentSquaresBB[m.from] & potential_movables_;
  movables_[1] |= AdjacentSquaresBB[m.from] & potential_movables_;

  player_ ^= 1;
}

std::priority_queue<AIBoard> AIBoard::get_child_states() const {
  // TODO: logic to replace find_all_moves() with something smarter.
  std::priority_queue<AIBoard> pq;
  find_all_moves();
  for (Move m : moves_) {
    AIBoard b;
    b.make_move(m);
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
  for (int i = 1; i < 9; ++i) {
    for (int j = 1; j < 9; ++j) {
      // TODO: add all moves

    }
  }
}
