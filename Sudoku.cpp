#include <iostream>
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

int main() {
	int size = sizeInput();
	ifstream in = fileInput();
	Board board(size, in);
	board.print();
	return 0;
}