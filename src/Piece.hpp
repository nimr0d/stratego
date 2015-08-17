#ifndef _H_PIECE_
#define _H_PIECE_

enum PieceType{
  REGULAR,
  MINER,
  SPY,
  BOMB,
  FLAG
};

class Piece{
public:
  Piece();
  Piece(short num);
  
  PieceType type() const;
  short value() const;
  bool player() const;
  void set_type(PieceType type);
  void set_value(short value);
  void set_player(bool player);
private:
  PieceType type;
  short value;
  bool player;
};

bool operator==(const Piece& p_left, const Piece& p_right);
bool operator<(const Piece& p_left, const Piece& p_right);



#endif
