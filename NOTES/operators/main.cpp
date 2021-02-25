#include <iostream>
using namespace std;

int countBits( unsigned int x ) {
	short num_bits = 0;
	while (x) {
		cout << "Unsigned int:\t" << x << endl;
		cout << "number of bits:\t" << num_bits << endl;

		// Using "bitwise AND" operator to add one to the count if the leading bit is 1;
		num_bits += x & 1;
		x >>= 1; // Shift x to the right ( divides by two );
	}
	cout << num_bits << endl;
	return num_bits;
}

int main() {
	//countBits(10);
	//cout << numeric_limits<int>::max() << endl;
	//cout << numeric_limits<long>::max() << endl;
	cout << fabs(-101);
	return 0;
}