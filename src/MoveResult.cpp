#include "MoveResult.hpp"

#include <stdio.h>

#include "Piece.hpp"

MoveResult::MoveResult(bool v, bool wtg, bool def, char voe) :
   valid_(v), won_the_game_(wtg), defeated_(def), value_of_enemy_(voe) {}

void MoveResult::print() const {
  if(won_the_game_){
    printf("Won the Game!\n");
  } else {
    if(defeated_){
      printf("defeated the enemy's %c", Piece::symbol(value_of_enemy_));
    } else{
      printf("lost to the enemy's %c",  Piece::symbol(value_of_enemy_));
    }
  }
}

bool MoveResult::is_valid() const {
  return valid_;
}
bool MoveResult::has_won_the_game() const {
  return won_the_game_;
}
bool MoveResult::has_defeated() const {
  return defeated_;
}
char MoveResult::value_of_enemy() const {
  return value_of_enemy_;
}
