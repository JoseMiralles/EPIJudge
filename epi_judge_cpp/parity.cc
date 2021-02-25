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

short Parity(unsigned long long x) {

	short result = 0;

	while (x) {
		// Flip result on each operation.
		result = result ^ 1;
		// Mask off the lowest set bit of x.
		x = x & (x - 1);
	}

	return result;

}

int main(int argc, char* argv[]) {
	std::vector<std::string> args{ argv + 1, argv + argc };
	std::vector<std::string> param_names{ "x" };
	return GenericTestMain(args, "parity.cc", "parity.tsv", &Parity,
		DefaultComparator{}, param_names);
}
