#include "Board.hpp"

#include <unordered_map>

#include <stdio.h>

#include "Piece.hpp"

Board::Board() {}

void Board::print(bool player) const{
  for(int i = 0; i < 10; ++i){
    for(int j = 0; j < 10; ++j){
      const Piece *tmp = &board_[i][j];
      if(tmp->empty()){
	printf(" ");
      }
      else{
	if(tmp->player() == player){
	  printf("%c", tmp->symbol());
	} else{
	  printf("?");
	}
      }
      printf(" ");
    }
    printf("\n");
  }
  printf("\n");
}
