/*
	Drills!
	This is a port of DRILLS.BAS in C++

	Roger Ngo
	2022-05-25
*/

#include <iostream>
#include <chrono>
#include <time.h>
#include <string>

using namespace std;

int MAX_RANDOM = 256;
string UNIT_MAP[] = { "b", "B", "KB", "MB", "GB", "TB" };
enum UNITS {
	UNIT_b = 1,
	UNIT_B = 2,
	UNIT_KB = 3,
	UNIT_MB = 4,
	UNIT_GB = 5,
	UNIT_TB = 6
};
float TOLERANCE = 0.01;

int main() {
	srand(time(NULL));

	std::cout << "Welcome to the Drills Game!" << endl;
	std::cout << "-> We assume units of 1000 rather than 1024" << endl;
	std::cout << "----------------------------" << endl;
	std::cout << "How many questions today? ";
	
	int totalQuestions = 0;
	int correctAnswers = 0;
	cin >> totalQuestions;

	if (totalQuestions == 0) {
		std::cout << "-> Looks like you don't want to play right now! Maybe later!" << endl;
	}

	auto start = chrono::system_clock::now();
	for (int i = 1; i <= totalQuestions; i++) {
		int sourceUnitIndex = rand() % 6 + 1;
		int destinationUnitIndex = rand() % 6 + 1;

		while (abs(sourceUnitIndex - destinationUnitIndex) != 1) {
			sourceUnitIndex = rand() % 6 + 1;
			destinationUnitIndex = rand() % 6 + 1;
		}

		string firstUnit = UNIT_MAP[sourceUnitIndex - 1];
		string secondUnit = UNIT_MAP[destinationUnitIndex - 1];

		int problemNumber = rand() % MAX_RANDOM + 1;
		std::cout << problemNumber << " " << firstUnit << " to " << secondUnit << "? ";
		
		float userAnswer = 0.0f;
		cin >> userAnswer;

		float realAnswer = 0.0f;
		if (sourceUnitIndex < destinationUnitIndex) {
			if (destinationUnitIndex == UNIT_B) {
				// bits to bytes
				realAnswer = problemNumber / 8.0;
			}
			else {
				realAnswer = problemNumber / 1000.0;
			}
		}
		else {
			if (destinationUnitIndex == UNIT_b) {
				// bytes to bits
				realAnswer = problemNumber * 8.0;
			}
			else {
				realAnswer = problemNumber * 1000.0;
			}
		}

		if (userAnswer < (realAnswer + TOLERANCE) && userAnswer > (realAnswer - TOLERANCE)) {
			std::cout << "-> Correct!" << endl;
			correctAnswers++;
		}
		else {
			std::cout << "-> Wrong!" << endl;
		}
	}

	auto end = chrono::system_clock::now();
	chrono::duration<double> elapsed = end - start;

	int seconds = int(elapsed.count()) % 60;
	int minutes = int(elapsed.count()) / 60;

	std::cout << "----------------------------" << endl;
	std::cout << "** Here is your score: " << correctAnswers << " correct out of " << totalQuestions << " **" << endl;
	std::cout << "-> You finished in " << minutes << " minutes and " << seconds << " seconds" << endl;
	std::cout << "Thanks for playing!" << endl;

	return 0;
}
