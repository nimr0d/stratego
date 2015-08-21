#ifndef _H_MOVE_
#define _H_MOVE_

enum Direction {
  UP,
  DOWN,
  LEFT,
  RIGHT,
};

struct Move {
  char from;
  char to;
};
#endif
