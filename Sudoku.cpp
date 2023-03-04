#include <iostream>
#include <sstream>
#include "Board.h"
using namespace std;

int sizeInput() {
	int size;
	cout << "Input a size: ";
	cin >> size;
	while (size < 1 || size > 9) {
		cout << "ERROR: SIZE MUST BE BETWEEN 1 AND 9" << endl;
		//clear the buffer
		if (cin.fail()) {
			cin.clear();
			string str;
			getline(cin, str);

		}
		cout << "Input a size: ";
		cin >> size;
	}
	return size;
}

ifstream fileInput() {
	cout << "Input a file name: ";
	string inputFile;
	cin >> inputFile;
	ifstream in(inputFile);
	while (in.fail()) {
		cout << "ERROR: CANNOT OPEN FILE: " << inputFile << endl;
		in.clear();
		cout << "Input a file name: ";
		cin >> inputFile;
		in.open(inputFile);
	}
	cout << endl;
	return in;
}


void isValidTests() {
	cout << "isValid() tests" << endl;

	int size = 9;
	ifstream in("input.txt");
	Board board(size, in);

	cout << "Expected: 0\nActual: " << board.isValid() << endl;
	in.close();

	in.open("completed.txt");
	Board board2(size, in);
	cout << "Expected: 1\nActual: " << board.isValid() << endl;
	in.close();
}

int main() {
	
	isValidTests(); // DEBUG

	int size = sizeInput();
	ifstream in = fileInput();
	Board board(size, in);
	cout << endl;

	/*while (!board.isValid()) {
		board.print();

	}*/
	board.print();
	//print congrats msg

	in.close();
	return 0;
}