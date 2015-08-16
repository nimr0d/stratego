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
  Piece(int num);
  
  bool      is_special()      const;
  PieceType get_type()        const;
  int       get_value() const;
private:
  bool is_special_piece;
  int  piece_value; //if not special
  PieceType type;
};


bool operator<(const Piece& p_left, const Piece& p_right);


#endif
