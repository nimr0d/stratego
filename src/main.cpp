#include <iostream>
#include "../test/test.hpp"
#include "Bitboard.hpp"

using namespace std;

int main() {
  cout << "Stratego" << endl;
  test();
  Bitboards::init();
  Bitboard b = CrosshairBB[69];
  b.print();
  return 0;
}


