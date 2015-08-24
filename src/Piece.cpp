#include "Piece.hpp"

Piece::Piece() : value_(0), player_(0) {}
Piece::Piece(char value, Player player) : value_(value), player_(player) {}

char Piece::value() const {
  return value_;
}

Player Piece::player() const {
  return player_;
}

char Piece::symbol() const {
  return symbol_[value_];
}

bool Piece::empty() const {
  return value_ == EMPTY;
}

void Piece::set_value(char value) {
  value_ = value;
}

void Piece::set_player(Player player) {
  player_ = player;
}

bool Piece::operator==(const Piece& other) const{
  return value_ == other.value_ && player_ == other.player();
}

bool Piece::operator!=(const Piece& other) const{
  return !(this->operator==(other));
}

bool Piece::defeats(const Piece& other) const{
  if (value_ == MINER && other.value_ == BOMB) return true;
  if (value_ == BOMB && other.value_ == MINER) return false;
  if (value_ == SPY && other.value_ == MARSHAL) return true;
  return value_ >= other.value_;
}

bool Piece::is_allowed_to_move() const{
  return !( value_ == BOMB ||  value_ == FLAG);
}

char symbol_from_value(char value){
  return Piece(value, 0).symbol();
}

const char Piece::symbol_[] = {' ', 'F', 'S', '2', '3', '4', '5', '6', '7', '8', '9', 'M', 'B'};


