#include "BoardFactory.hpp"


#include <stdio.h>

#include "Move.hpp"
#include "Piece.hpp"
#include "Board.hpp"



Board board_factory_1(){
  Board b;
  
  b.set_piece(Piece(6,0), 2, 2);
  b.set_piece(Piece(6,0), 2, 3);
  b.set_piece(Piece(6,1), 2, 4);
  b.set_piece(Piece(6,0), 3, 4);
  b.set_piece(Piece(SCOUT,0), 4, 4);
  
  
  printf("board 1 as viewd by player 0\n");
  b.print(0);
  printf("board 1 as viewd by player 1\n");
  b.print(1);
  
  return b;
}


Board board_factory_2(){
  Board b;
  
  b.set_piece(Piece(6,0), 1, 1);
  b.set_piece(Piece(6,0), 2, 3);
  b.set_piece(Piece(6,1), 4, 2);
  b.set_piece(Piece(6,0), 3, 4);
  b.set_piece(Piece(SCOUT,0), 4, 4);
  
  
  printf("board 2 as viewd by player 0\n");
  b.print(0);
  printf("board 2 as viewd by player 1\n");
  b.print(1);
  
  return b;
}
