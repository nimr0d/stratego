#include <iostream>
#include "../test/test.hpp"
#include "AIBoard.hpp"
#include "Bitboard.hpp"

using namespace std;

int main() {
  cout << "Stratego" << endl;

  Bitboards::init();

  test();

  return 0;
}


