#include "BoardIO.hpp"

#include <string>
#include <iostream>

#include <stdio.h>

#include "Piece.hpp"


void print_board(const Board& b, bool p){
  b.print(p);
}

void ignore_number_of_chars(FILE *fd, int n){
  char buffer; 
  for(int i = 0; i < n; ++i){
    buffer = fgetc(fd);
  }
}



Board read_board_from_file(std::string file_name){
  FILE* fd = fopen(file_name.c_str(), "r");
  char buffer;
  Board b; 
  ignore_number_of_chars(fd, 30);
  //printf("Char read: %c \n", fgetc(fd));
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      char type, player;
      type = fgetc(fd);
      player = fgetc(fd);
      if(type != '.'){
	printf("type: %c player: %c \n", type, player);
	b.set_piece(Piece(type, player, player), i, j);
      }
      ignore_number_of_chars(fd, 1);
    }
    ignore_number_of_chars(fd, 32);
    printf("_____ \n");
  }
  fclose(fd);
  return b; 
}

void write_board_to_file(std::string file_name, const Board& b){
  FILE* fd = fopen(file_name.c_str(), "w");
  for(int i = 0; i < 29; ++i){
    fprintf(fd,"_");
  }
  fprintf(fd,"\n");
  for(int i = 0; i < 10; ++i){
    for(int j = 0; j < 10; ++j){
      Piece tmp = b.piece(i, j);
      if(tmp.empty()){
	fprintf(fd, "..");
      }
      else{
	fprintf(fd, "%c%d", tmp.symbol(), tmp.player());
      }
      fprintf(fd, " ");
    }
    fprintf(fd, "\n");
    for(int j = 0; j < 10; ++j){
      Piece tmp = b.piece(i, j);
      if(tmp.empty()){
	fprintf(fd, "..");
      }
      else{
	fprintf(fd, "%d%c",tmp.player(), tmp.symbol());
      }
      fprintf(fd, " ");
    }
    fprintf(fd, "\n");
  }
  for(int i = 0; i < 29; ++i){
    fprintf(fd, "_");
  }
  fprintf(fd, "\n");
  fclose(fd);
}
