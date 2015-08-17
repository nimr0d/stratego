#ifndef _H_PIECE_
#define _H_PIECE_

#include "Player.hpp"

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
  Piece(char value, Player player);
  char value() const;
  Player player() const;
  char symbol() const;
  bool empty() const;
  void set_value(char value);
  void set_player(Player player);
  
  bool operator==(const Piece& other) const;
  bool operator<(const Piece& other) const; 

  bool operator!=(const Piece& other) const;
  bool operator> (const Piece& other) const; 
  bool operator<=(const Piece& other) const; 
  bool operator>=(const Piece& other) const; 
  // When piece is attacking other. No errors on undefined behavior.
private:
  char value_;
  Player player_;
  
  static const char symbol_[];
};




#endif
