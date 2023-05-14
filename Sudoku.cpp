#include <iostream>
#include <sstream>
#include "Board.h"
using namespace std;

//int sizeInput() {
//	int size;
//	cout << "Input a size: ";
//	cin >> size;
//	while (size < 1 || size > 9) {
//		cout << "ERROR: SIZE MUST BE BETWEEN 1 AND 9" << endl;
//		//clear the buffer
//		if (cin.fail()) {
//			cin.clear();
//			string str;
//			getline(cin, str);
//
//		}
//		cout << "Input a size: ";
//		cin >> size;
//	}
//	return size;
//}

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
	return in;
}

pair<int, int> convert(int row, int col) {
	return {BOARD_SIZE - row, col - 1};
	//return { col - 1, BOARD_SIZE - row - 1};
}

void clearCin() {
	cin.clear();
	string str;
	getline(cin, str);
}

int main() {
	ifstream in = fileInput();
	Board board(in);
	in.close();
	//Board board;
	clearCin();
	while (!board.full()) {
		string input;
		int val;
		int row;
		int col;
		board.print();
		cout << "Enter:\n [1] val, col, row\n [2] save" << endl;
		//cin >> val >> col >> row;
		getline(cin, input);
		if (input == "save") {
			break;
		}
		else {
			stringstream ss;
			ss << input;
			ss >> val >> col >> row;
		}
		system("cls");
		pair<int, int> rowCol = convert(row, col);
		try {
			board.insert(val, rowCol.first, rowCol.second);
		}
		catch (const NumException& e) {
			cout << "ERROR: cell already contains a number" << endl;
			//clearCin();
		}
		catch (const ValException& e) {
			cout << "ERROR: val must be between 1 and 9" << endl;
			clearCin();
		}
		catch (const RowException& e) {
			cout << "ERROR: row must be between 1 and 9" << endl;
			clearCin();
		}
		catch (const ColException& e){
			cout << "ERROR: col must be between 1 and 9" << endl;
			clearCin();
		}
		catch (const RowNumException& e) {
			cout << "ERROR: Row cannot contain duplicates" << endl;
		}
		catch (const ColNumException& e) {
			cout << "ERROR: Col cannot contain duplicates" << endl;
		}
		catch (const SquareException& e) {
			cout << "ERROR: Square cannot contain duplicates" << endl;
		}
	}

	ofstream out("output.txt");
	out << board.out();
	cout << "Saved board state in output.txt";
	out.close();

	
	return 0;
}