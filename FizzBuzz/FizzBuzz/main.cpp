// FizzBuzz
// 2022-05-28

#include <iostream>

using namespace std;

int main() {
	// FizzBuzz if the number if divisible by 3 and 5
	// Fizz if the number is divisible by 3
	// Buzz if the number is divisble by 5
	// Otherwise, the number
	int iterations;

	cout << "How many iterations?" << endl;
	cin >> iterations;

	for (int i = 1; i <= iterations; i++) {
		if (i % 3 == 0 && i % 5 == 0) {
			cout << i << ": " << "FizzBuzz" << endl;
		}
		else if (i % 3 == 0) {
			cout << i << ": " << "Fizz" << endl;
		}
		else if (i % 5 == 0) {
			cout << i << ": " << "Buzz" << endl;
		}
		else {
			cout << i << ": " << i << endl;
		}
	}
	return 0;
}