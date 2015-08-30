#ifndef _H_BITBOARD_
#define _H_BITBOARD_
class Bitboard {
	public:
		Bitboard() = default;

		Bitboard(unsigned long long b0, unsigned long long b1) : b_{b0, b1} {}

		Bitboard operator<<(int shift) const {
			if (shift >= 64) {
				return Bitboard(0ULL, b_[0] << (shift - 64));
			}
			if (shift == 0) return *this;
			return Bitboard(b_[0] << shift, (b_[1] << shift) | (b_[0] >> (64 - shift)));
		}

		Bitboard operator>>(int shift) const {
			if (shift >= 64) {
				return Bitboard(b_[1] >> (shift - 64), 0ULL);
			}
			if (shift == 0) return *this;
			return Bitboard((b_[0] >> shift) | (b_[1] << (64 - shift)), b_[1] >> shift);
		}

		Bitboard operator&(const Bitboard& other) const {
			return Bitboard(b_[0] & other.b_[0], b_[1] & other.b_[1]);
		}

		void operator&=(const Bitboard& other) {
			b_[0] &= other.b_[0];
			b_[1] &= other.b_[1]; 
		}

		Bitboard operator|(const Bitboard& other) const {
			return Bitboard(b_[0] | other.b_[0], b_[1] | other.b_[1]);
		}

		void operator|=(const Bitboard& other) {
			b_[0] |= other.b_[0];
			b_[1] |= other.b_[1]; 
		}

		Bitboard operator^(const Bitboard& other) const {
			return Bitboard(b_[0] ^ other.b_[0], b_[1] ^ other.b_[1]);
		}

		void operator^=(const Bitboard& other) {
			b_[0] ^= other.b_[0];
			b_[1] ^= other.b_[1];
		}

		bool operator==(const Bitboard& other) const {
			return b_[0] == other.b_[0] && b_[1] == other.b_[1];
		}

		bool operator!=(const Bitboard& other) const {
			return (b_[0] ^ other.b_[0]) || (b_[1] ^ other.b_[1]);
		}

		explicit operator bool() const { 
		    return b_[0] | b_[1]; 
		}

		void print() const;
	
	private:
		unsigned long long b_[2];

};

extern Bitboard SquareBB[100]; // Bitboard for each square
extern Bitboard AdjacentSquaresBB[100]; // Bitboard of adjacent squares for each square
extern Bitboard ColumnBB[10];
extern Bitboard RowBB[10];
extern Bitboard CrosshairBB[100]; // Row and column for every square
extern Bitboard WaterAreasBB;
namespace Bitboards {
void init();
}
#endif