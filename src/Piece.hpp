#ifndef _H_PIECE_
#define _H_PIECE_

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
  Piece(char value, bool player);
  char value() const;
  bool player() const;
  char symbol() const;
  static char symbol(char value);
  bool empty() const;
  void set_value(char value);
  void set_player(bool player);
  bool operator==(const Piece& other) const;
  bool operator!=(const Piece& other) const;
  bool defeats(const Piece& other) const; // When piece is attacking other. No errors on undefined comparisons.
  bool is_movable() const;
private:
  char value_;
  bool player_;
  static const char symbol_[];
};

#endif
