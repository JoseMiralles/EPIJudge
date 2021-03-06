// 1011 returns 1 since the number of 1s is odd.
// 10001000 returns 0 since the number of 1s is even.

#include "test_framework/generic_test.h"

// O(n) where n is the number of bits in the word.
short ParityNaive(unsigned long long x) {

	short result = 0;

	while (x) {
		// Flip result back and forward everytime x & 1 == 1.
		// This will make result == 0 when k % 2 == 0 and 1 when k % 2 != 0.
		// K being the number of 1s in the bit word.
		result = result ^ (x & 1);
		x >>= 1;
	}

	return result;

}

// O(k), k = number of ones in the bit word.
short ParityOK(unsigned long long x) {

	short result = 0;

	while (x) {
		// Flip result on each operation.
		result = result ^ 1;
		// Mask off the lowest set bit of x.
		x = x & (x - 1);
	}

	return result;

}

/// The efficient solution.
/*
	The parity of 11010111 is the same as the parity
	of the result of 1101 XOR 0111, which is 1010.
	Then, the parity of 1010 is the same as the parity of
	the result of 10 XOR 10, which is 00.
	The parity of 00 is 0.

	This means that the parity of 11010111 is 0.
*/
// O(log n)
short Parity(unsigned long long x) {
	// Example: x = 11010111
					// x = x XOR shifted = result
	x ^= x >> 32;	// x = 11010111 ^ 0 = 11010111
	x ^= x >> 16;	// x = 11010111 ^ 0 = 11010111
	x ^= x >> 8;	// x = 11010111 ^ 0 = 11010111
	x ^= x >> 4;	// x = 11010111 ^ 1101 = 11011010
	x ^= x >> 2;	// x = 11011010 ^ 110110 = 11101100
	x ^= x >> 1;	// x = 11101100 ^ 1110110 = 10011010
	return x & 0x1;
}

int main(int argc, char* argv[]) {
	std::vector<std::string> args{ argv + 1, argv + argc };
	std::vector<std::string> param_names{ "x" };
	return GenericTestMain(args, "parity.cc", "parity.tsv", &Parity,
		DefaultComparator{}, param_names);
}
