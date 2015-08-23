#include "MoveResult.hpp"

MoveResult::MoveResult(bool v_, bool wtg_, bool def_, char voe_){
  valid_ = v_;
  won_the_game_ = wtg_;
  defeated_ = def_;
  value_of_enemy_ = voe_;
}


bool MoveResult::is_valid()         const{
  return valid_;
}
bool MoveResult::has_won_the_game() const{
  return won_the_game_;
}
bool MoveResult::has_defeated()     const{
  return defeated_;
}
char MoveResult::value_of_enemy()   const{
  return value_of_enemy_;
}
