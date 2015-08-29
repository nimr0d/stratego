#include "Bitboard.hpp"
#include <iostream>

void Bitboard::print() {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			char c = 10 * i + j;
			if (c < 64) {
				std::cout << ((b_[0] >> c) & 1) << " ";
			} else {
				std::cout << ((b_[1] >> (c - 64)) & 1) << " ";
			}
		}
		std::cout << "\n";
	}
}

Bitboard SquareBB[100];
Bitboard AdjacentSquaresBB[100];
Bitboard ColumnBB[10];
Bitboard RowBB[10];
Bitboard CrosshairBB[100];

void Bitboards::init() {
	for (char i = 0; i < 10; ++i) {
		RowBB[i] = Bitboard(0x3ffULL, 0ULL) << 10 * i;
	}

	for (char i = 0; i < 10; ++i) {
		ColumnBB[i] = Bitboard(0x1004010040100401ULL, 0x4010040ULL) << i;
	}

	for (char s = 0; s < 100; ++s) {
		if (s < 64) {
			SquareBB[s] = Bitboard(1ULL << s, 0ULL);
		} else {
			SquareBB[s] = Bitboard(0ULL, 1ULL << (s - 64));
		}
		AdjacentSquaresBB[s] = Bitboard(0ULL, 0ULL);

		CrosshairBB[s] = RowBB[s / 10] ^ ColumnBB[s % 10];
	}

	for (char s = 0; s < 100; ++s) {
		if (s < 90) {
		  AdjacentSquaresBB[s + 10] |= SquareBB[s];
		}
		if (s >= 10) {
		  AdjacentSquaresBB[s - 10] |= SquareBB[s];
		}
		if (s % 10 < 9) {
		  AdjacentSquaresBB[s + 1] |= SquareBB[s];
		}
		if (s % 10 > 0) {
		  AdjacentSquaresBB[s - 1] |= SquareBB[s];
		}
	}
}