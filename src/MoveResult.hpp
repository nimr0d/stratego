#ifndef _H_MOVE_RESULT
#define _H_MOVE_RESULT


class MoveResult{
public:
  MoveResult(bool v_, bool wtg_, bool def_, char voe_);
  
  bool is_valid() const;
  bool has_won_the_game() const;
  bool has_defeated() const;
  char value_of_enemy() const;   
  
  void print() const; 
private:
  bool valid_;
  bool won_the_game_;
  bool defeated_;
  char value_of_enemy_;
};

#endif
