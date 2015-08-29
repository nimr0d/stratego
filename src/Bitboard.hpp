#ifndef _H_BITBOARD_
#define _H_BITBOARD_
class Bitboard {
	public:
		Bitboard() = default;

		Bitboard(unsigned long long b0, unsigned long long b1) {
			b_[0] = b0;
			b_[1] = b1;
		}

		Bitboard(const Bitboard& other) {
			b_[0] = other.b_[0];
			b_[1] = other.b_[1];
		}

		Bitboard operator<<(int i) {
			unsigned long long r;
			if (i < 64) {
				r = b_[0] >> (64 - i);
			} else {
				r = b_[0] << (i - 64);
			}
			return Bitboard(b_[0] << i, (b_[1] << i) | r);
		}

		Bitboard operator>>(int i) {
			unsigned long long r;
			if (i < 64) {
				r = b_[1] << (64 - i);
			} else {
				r = b_[1] >> (i - 64);
			}
			return Bitboard((b_[0] >> i) | r, b_[1] >> i);
		}

		Bitboard operator&(const Bitboard& other) {
			return Bitboard(b_[0] & other.b_[0], b_[1] & other.b_[1]);
		}

		Bitboard operator|(const Bitboard& other) {
			return Bitboard(b_[0] | other.b_[0], b_[1] | other.b_[1]);
		}

		void operator|=(const Bitboard& other) {
			b_[0] |= other.b_[0];
			b_[1] |= other.b_[1]; 
		}

		Bitboard operator^(const Bitboard& other) {
			return Bitboard(b_[0] ^ other.b_[0], b_[1] ^ other.b_[1]);
		}

		void operator^=(const Bitboard& other) {
			b_[0] ^= other.b_[0];
			b_[1] ^= other.b_[1];
		}

		void operator=(const Bitboard& other) {
			b_[0] = other.b_[0];
			b_[1] = other.b_[1];
		}

		bool operator==(const Bitboard& other) {
			return b_[0] == other.b_[0] && b_[1] == other.b_[1];
		}

		explicit operator bool() const { 
		    return b_[0] | b_[1]; 
		}

		void print();
	private:
		unsigned long long b_[2];

};
extern Bitboard SquareBB[100]; // Bitboard for each square
extern Bitboard AdjacentSquaresBB[100]; // Bitboard of adjacent squares for each square
extern Bitboard ColumnBB[10];
extern Bitboard RowBB[10];
extern Bitboard CrosshairBB[100]; // Row and column for every square
namespace Bitboards {
void init();
}
#endif