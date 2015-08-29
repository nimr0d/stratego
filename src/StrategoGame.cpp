#include "StrategoGame.hpp"

#include <stdio.h>

#include "Board.hpp"
#include "Move.hpp"
#include "MoveResult.hpp"
#include "Player.hpp"

Move StrategoGame::ask_player_to_make_move(bool p){
  return players_[p]->get_move();
}

void StrategoGame::send_move_result_to_player(MoveResult move_result, bool p){
  players_[p]->send_results_of_move(move_result);
}

void StrategoGame::play_game(){
  printf("Playing the game!\n");

  while(true){
    Move move = ask_player_to_make_move(state_.player());
    MoveResult move_result = state_.get_move_result(move); 
    while(!move_result.is_valid()){
      printf("MOVE WAS INVALID!! TYPE AGAIN PLEASE\n");
      move = ask_player_to_make_move(state_.player());
      move_result = state_.get_move_result(move); 
    }
    
    send_move_result_to_player(move_result, state_.player());
    state_ = state_.make_move(move);
    
    if(move_result.has_won_the_game()){
      printf("Player %d has won the game!\n", state_.player());
      break;
    }
  }
}
