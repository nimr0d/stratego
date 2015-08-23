#ifndef _H_PIECE_
#define _H_PIECE_

#include "Player.hpp"

enum Piece_Type {
  EMPTY = 0,
  FLAG = 1,
  SPY = 2,
  SCOUT = 3,
  MINER = 4,
  MARSHAL = 11,
  BOMB = 12,
  UNKNOWN = 13,
};

class Piece{
public:
  Piece();
  Piece(char value, Player player);
  char value() const;
  Player player() const;
  char symbol() const;
  bool empty() const;
  void set_value(char value);
  void set_player(Player player);
  bool operator==(const Piece& other) const;
  bool operator!=(const Piece& other) const;
  bool defeats(const Piece& other) const; // When piece is attacking other. No errors on undefined comparisons.
  bool is_allowed_to_move() const;
private:
  char value_;
  Player player_;
  static const char symbol_[];
};


#endif
