#include "AIBoard.hpp"

#include <assert.h>
#include <queue>
#include <vector>

struct Eval {
  float eval;
  char index;
  bool operator==(const Eval& other) const {
    return index == other.index || eval == other.eval;
  }
  bool operator<(const Eval& other) const {
    return eval < other.eval;
  }
};

AIBoard::AIBoard() : player_(0){}

float AIBoard::evaluate() const{
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
      if ((AdjacentSquaresBB[s] & bad_dest_[board_[s].player()]) != AdjacentSquaresBB[s]) {
        movables_[board_[s].player()] |= SquareBB[s];
      }
    }
  }
}

void AIBoard::make_move(char from, char to) {
  Piece p1 = piece(from);
  Piece p2 = piece(to);
  if(p1.defeats(p2)) {
    set_piece(p1, to);

    bad_dest_[player_] |= SquareBB[to]; // Player changed in to.
    if (!p2.empty()) {
      bad_dest_[!player_] ^= SquareBB[to];
    }

    potential_movables_ |= SquareBB[to]; // Movable piece moved into to.
    //Pieces around to which are the other player's are now movable.

    Bitboard b = AdjacentSquaresBB[to] & bad_dest_[player_] & potential_movables_;
    char s;
    while (s = b.unset_lsb()) {
      --s;
      if ((AdjacentSquaresBB[s] & bad_dest_[player_]) == AdjacentSquaresBB[s]) {
        movables_[player_] &= ~SquareBB[s];
      }
    }
    movables_[player_] |= SquareBB[to];
    movables_[!player_] &= ~SquareBB[to];
    movables_[!player_] |= AdjacentSquaresBB[to] & bad_dest_[!player_] & potential_movables_;
  }

  // from is now empty.
  set_piece(Piece(EMPTY,player_), from);
  bad_dest_[player_] ^= SquareBB[from];
  movables_[player_] &= ~SquareBB[from];
  potential_movables_ ^= SquareBB[from];

  // Pieces around from are now movable.
  movables_[0] |= AdjacentSquaresBB[from] & potential_movables_ & bad_dest_[0];
  movables_[1] |= AdjacentSquaresBB[from] & potential_movables_ & bad_dest_[1];

  player_ ^= 1;
}

void AIBoard::get_children() const{
  std::vector<AIBoard*> children;
  std::priority_queue<Eval> q;

  Bitboard movables = movables_[player_];
  char s_from;
  while (s_from = movables.unset_lsb()) {
    --s_from;
    Bitboard dests = AdjacentSquaresBB[s_from] & ~bad_dest_[player_];
    char s_to;
    while (s_to = dests.unset_lsb()) {
      --s_to;
      AIBoard child(*this);
      child.make_move(s_from, s_to);
        Eval e;
      e.eval = child.evaluate();
      e.index = children.size();
      children.push_back(&child);
      q.push(e);

      child.print();
    }
  }
}
