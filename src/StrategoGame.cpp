#include "StrategoGame.hpp"

#include <stdio.h>


#include "Board.hpp"
#include "Player.hpp"
#include "Participent.hpp"

Move StrategoGame::ask_participent_to_move(Player p){
  return participents_[p].get_move();
}

void StrategoGame::send_move_results_to_participent(MoveResult move_result, Player p){
  participents_[p].send_results_of_move(move_result);
}

void StrategoGame::play_game(){
  printf("Playing the game!\n");

  while(true){
    Move move = ask_participent_to_make_move(_state.player());
    MoveResult move_result = _state.get_move_result(move); 
    while(!move_result.is_valid()){
      cout << "MOVE WAS INVALID!! TYPE AGAIN PLEASE" << endl;
      move = ask_player_to_move(p);
      move_result = _state.get_move_result(move); 
    }
    
    send_move_result_to_player(move_result, _state.player());
    _state = _state.make_move(move);
    
    if(move_result.has_won_the_game()){
      printf("Player %d has won the game!\n", p);
      break;
    }
  }
}
