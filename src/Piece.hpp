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
  void set_value(short value);
  void set_type(PieceType type);
private:  
  short value;
  bool player;
  PieceType type;
};

bool operator==(const Piece& p_left, const Piece& p_right);
bool operator<(const Piece& p_left, const Piece& p_right);



#endif
