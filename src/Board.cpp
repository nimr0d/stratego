#include "Board.hpp"

#include <unordered_map>

#include <stdio.h>

#include "Piece.hpp"
#include "Player.hpp"

void Board::print(Player _player) const{
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      Piece tmp = board[i][j];
      if(tmp.is_empty()){
	printf(" ");
      }
      else{
	if(tmp.get_player() == _player){
	  tmp.print();
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

Board::Board(){
}
