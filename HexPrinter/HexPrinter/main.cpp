/*
	HexPrinter
	Will print a given decimal number in hex

	Roger Ngo
	2022-05-28
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	bool hasQuit = false;

	while (!hasQuit) {
		int input;

		cout << "What is your number? ";
		cin >> input;

		int quotient = input;

		string number = "";
		while (quotient > 0) {
			int remainder = quotient % 16;
			quotient = quotient / 16;

			if (remainder >= 10) {
				number = (char)('A' + (remainder - 10)) + number;
			}
			else {
				number = (char)('0' + (remainder)) + number;
			}
		}

		cout << "-> The answer is " << number << endl;

		char isProcessAgain;
		cout << "Press 'q' to quit or any key to process again. ";
		cin >> isProcessAgain;
		if (isProcessAgain == 'q') {
			hasQuit = true;
		}
		cout << endl;
	}


	return 0;
}