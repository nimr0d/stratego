#ifndef _H_PIECE_
#define _H_PIECE_

#define EMPTY 0
#define FLAG 1
#define SPY 2
#define SCOUT 3
#define MINER 4
#define MARSHAL 11
#define BOMB 12

class Piece{
public:
  Piece();
  Piece(char value, bool player);
  char value() const;
  bool player() const;
  char symbol() const;
  bool empty() const;
  void set_value(char value);
  void set_player(bool player);
private:
  char value_;
  bool player_;
  char const symbol_[13] = {' ', 'F', 'S', '2', '3', '4', '5', '6', '7', '8', '9', 'M', 'B'};
  bool operator==(const Piece& other);
  bool operator<(const Piece& other); // When piece is attacking other. No errors on undefined behavior.
};

#endif
