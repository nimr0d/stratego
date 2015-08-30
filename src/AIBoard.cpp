#include "AIBoard.hpp"

#include <assert.h>

AIBoard::AIBoard() : player_(0){}

float AIBoard::evaluate() {
  // TODO: evaluation code
  return 0;
}

Piece AIBoard::piece(char pos) const {
  return board_[pos]; 
}

void AIBoard::set_piece(Piece p, char pos) {
  board_[pos] = p; 
}

bool AIBoard::player() const {
  return player_;
}

void AIBoard::set_player(bool player) {
  player_ = player;
}

void AIBoard::update_bitboards() {
  bad_dest_[0] = WaterAreasBB;
  bad_dest_[1] = WaterAreasBB;
  movables_[0] = Bitboard(0ULL, 0ULL);
  movables_[1] = Bitboard(0ULL, 0ULL);
  potential_movables_ = Bitboard(0ULL, 0ULL);
  for (char s = 0; s < 100; ++s) {
    if (!board_[s].empty()) {
      bad_dest_[board_[s].player()] |= SquareBB[s];
    }
  }
  for (char s = 0; s < 100; ++s) {
    if (board_[s].is_movable()) {
      potential_movables_ |= SquareBB[s];
      if ((AdjacentSquaresBB[s] & bad_dest_[player_]) != AdjacentSquaresBB[s]) {
        movables_[board_[s].player()] |= SquareBB[s];
      }
    }
  }
}

void AIBoard::make_move(AIMove m) {
  Piece p1 = piece(m.from);
  Piece p2 = piece(m.to);
  if(p1.defeats(p2)) {
    set_piece(p1, m.to);

    bad_dest_[player_] |= SquareBB[m.to]; // Player changed in m.to.
    if (!p2.empty()) {
      bad_dest_[!player_] ^= SquareBB[m.to];
    }

    potential_movables_ |= SquareBB[m.to]; // Movable piece moved into m.to.
    //Pieces around m.to which are the other player's are now movable.

    Bitboard b = AdjacentSquaresBB[m.to] & bad_dest_[player_] & potential_movables_;
    // TODO: Fix this to make use of bitboard serialization
    for (char s = (m.to > 9 ? m.to - 10 : 0); s <= m.to + 10; ++s) {
      if (bool(b & SquareBB[s]) && (AdjacentSquaresBB[s] & bad_dest_[player_]) == AdjacentSquaresBB[s]) {
        movables_[player_] |= SquareBB[s];
      }
    }

    movables_[!player_] |= AdjacentSquaresBB[m.to] & bad_dest_[!player_] & potential_movables_;
  }

  // m.from is now empty.
  set_piece(Piece(EMPTY,player_), m.from);
  bad_dest_[player_] ^= SquareBB[m.from];
  movables_[player_] ^= SquareBB[m.from];
  potential_movables_ ^= SquareBB[m.from];

  // Pieces around m.from are now movable.
  movables_[0] |= AdjacentSquaresBB[m.from] & potential_movables_ & bad_dest_[0];
  movables_[1] |= AdjacentSquaresBB[m.from] & potential_movables_ & bad_dest_[1];

  player_ ^= 1;
}

void AIBoard::find_all_moves() {
  for (int i = 1; i < 9; ++i) {
    for (int j = 1; j < 9; ++j) {
      // TODO: add all moves

    }
  }
}
