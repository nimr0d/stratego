#include "Piece.hpp"

Piece::Piece() : value_(0), player_(0) {}
Piece::Piece(char value, bool player) : value_(value), player_(player) {}

char Piece::value() const {
  return value_;
}

bool Piece::player() const {
  return player_;
}

char Piece::symbol() const {
  return symbol_[value_];
}

bool Piece::empty() const {
  return value_ == 0;
}

void Piece::set_value(char value) {
  value_ = value;
}

void Piece::set_player(bool player) {
  player_ = player;
}


bool Piece::operator==(const Piece& other) {
  return value_ == other.value_;
}

bool Piece::operator<(const Piece& other){
  if (value_ == MINER && other.value_ == BOMB) return false;
  if (value_ == SPY && other.value_ == MARSHAL) return false;
  return value_ < other.value_;
}

