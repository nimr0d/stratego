#include "BoardIO.hpp"

#include <string>
#include <iostream>

#include <stdio.h>

#include "Board.hpp"
#include "Piece.hpp"
#include "Player.hpp"


void print_board(const Board& b, Player p){
  b.print(p);
}

void write_board_to_file(std::string file_name, const Board& b, Player p){
  FILE* fd = fopen(file_name.c_str(), "w");
  for(int i = 0; i < 10; ++i){
    fprintf(fd,"__");
  }
  fprintf(fd,"\n");
  for(int i = 0; i < 10; ++i){
    for(int j = 0; j < 10; ++j){
      Piece tmp = b.piece(i, j);
      if(tmp.empty()){
	fprintf(fd, ".");
      }
      else{
	if(tmp.player() == p){
	  fprintf(fd, "%c", tmp.symbol());
	} else{
	  fprintf(fd, "?");
	}
      }
      fprintf(fd, " ");
    }
    fprintf(fd, "\n");
  }
  for(int i = 0; i < 10; ++i){
    fprintf(fd, "__");
  }
  fprintf(fd, "\n");
  fclose(fd);
}
