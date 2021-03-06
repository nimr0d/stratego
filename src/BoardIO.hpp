#ifndef _H_BOARD_IO
#define _H_BOARD_IO

#include <string>

#include "Board.hpp"

void print_board(const Board& b, bool p);
void write_board_to_file(std::string file_name, const Board& b);
void write_board_web_view(std::string file_name, const Board& b);

Board read_board_from_file(std::string file_name);


#endif
