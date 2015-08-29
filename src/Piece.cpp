#include "Piece.hpp"

Piece::Piece() : value_(0), player_(0) {}
Piece::Piece(char value, bool player) : value_(value), player_(player) {}


Piece::Piece(char value, char player, char unused){
  player_ = (player == '1');
  for(int i = 0; i < 14; i++){
    if(value == symbol_[i]){
      value_ = i;
      break;
    }
  }
}

char Piece::value() const {
  return value_;
}

bool Piece::player() const {
  return player_;
}

char Piece::symbol() const {
  return symbol_[value_];
}

char Piece::symbol(char value) {
  return symbol_[value];
}

bool Piece::empty() const {
  return value_ == EMPTY;
}

void Piece::set_value(char value) {
  value_ = value;
}

void Piece::set_player(bool player) {
  player_ = player;
}

bool Piece::operator==(const Piece& other) const {
  return value_ == other.value_ && player_ == other.player_;
}

bool Piece::operator!=(const Piece& other) const {
  return !(this->operator==(other));
}

bool Piece::defeats(const Piece& other) const {
  if (value_ == MINER && other.value_ == BOMB) return true;
  if (value_ == BOMB && other.value_ == MINER) return false;
  if (value_ == SPY && other.value_ == MARSHAL) return true;
  return value_ >= other.value_;
}

bool Piece::is_movable() const {
  return !(value_ == BOMB || value_ == FLAG || value_ == EMPTY);
}

const char Piece::symbol_[] = {' ', 'F', 'S', '2', '3', '4', '5', '6', '7', '8', '9', 'M', 'B', '?'};

