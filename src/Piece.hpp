#ifndef _H_PIECE_
#define _H_PIECE_

#define FLAG 0
#define SPY 1
#define SCOUT 2
#define MINER 3
#define MARSHAL 10
#define BOMB 11

class Piece{
public:
  Piece();
  Piece(short num);
  short value() const;
  bool player() const;
  void set_value(short value);
  void set_player(bool player);
private:
  short value;
  bool player;
};

bool operator==(const Piece& p_left, const Piece& p_right);
bool operator<(const Piece& p_left, const Piece& p_right);


#endif
