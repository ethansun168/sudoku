#include "Board.h"
using namespace std;



Board::Board() {
	for (int row = 0; row < BOARD_SIZE; row++) {
		for (int col = 0; col < BOARD_SIZE; col++) {
			board[row][col] = 0;
		}
	}
}

Board::Board(ifstream& in) {
	for (int row = 0; row < BOARD_SIZE; row++) {
		for (int col = 0; col < BOARD_SIZE; col++) {
			in >> board[row][col];
		}
	}
}

//print the 2d array
void Board::print() {
	cout << "  ";
	for (int i = 0; i < BOARD_SIZE; i++) {
		cout << "__";
	}
	cout << endl;
	for (int row = 0; row < BOARD_SIZE; row++) {
		cout << BOARD_SIZE - row << "|";
		
		for (int col = 0; col < BOARD_SIZE; col++) {
			if (board[row][col] == 0) {
				cout << ".";
			}
			else {
				cout << board[row][col];
			}

			if ((col + 1) % 3 == 0) {
				cout << "|";
			}
			else {
				cout << " ";
			}
		}
		if ((row + 1) % 3 == 0) {
			cout << endl << " |";
			for (int i = 0; i < BOARD_SIZE / 3; i++) {
				cout << "_____|";
			}
		}
		cout << endl;
	}
	
	cout << "  ";
	for (int i = 0; i < BOARD_SIZE; i++) {
		cout << i + 1 << " ";
	}
	cout << endl;
}

bool Board::hasRowDuplicate() const {
	for (int row = 0; row < BOARD_SIZE; row++) {
		int temp[BOARD_SIZE];
		//copy row into temp
		for (int col = 0; col < BOARD_SIZE; col++) {
			temp[col] = board[row][col];
		}
		sort(temp, temp + BOARD_SIZE);
		for (int col = 0; col < BOARD_SIZE - 1; col++) {
			if (temp[col] != 0 && temp[col] == temp[col + 1] ) {
				return true;
			}
		}
	}
	return false;
}

bool Board::hasColDuplicate() const {
	for (int col = 0; col < BOARD_SIZE; col++) {
		int temp[BOARD_SIZE];
		//copy row into temp
		for (int row= 0; row < BOARD_SIZE; row++) {
			temp[row] = board[row][col];
		}
		sort(temp, temp + BOARD_SIZE);
		for (int row = 0; row < BOARD_SIZE - 1; row ++) {
			if (temp[row] != 0 && temp[row] == temp[row + 1]) {
				return true;
			}
		}
	}
	return false;
}

bool Board::hasSquareDuplicateHelper(int rowStart, int rowEnd, int colStart, int colEnd) const {
	int temp[BOARD_SIZE];
	int index = 0;
	for (int row = rowStart; row < rowEnd; row++) {
		for (int col = colStart; col < colEnd; col++) {
			temp[index] = board[row][col];
			index++;
		}
	}
	sort(temp, temp + BOARD_SIZE);
	for (int i = 0; i < BOARD_SIZE - 1; i++) {
		if (temp[i] != 0 && temp[i] == temp[i + 1]) {
			return true;
		}
	}
	return false;
}

bool Board::hasSquareDuplicate() const {
	/*
	row 0,1,2 * col 0,1,2
	row 0,1,2 * col 3,4,5
	row 0,1,2 * col 6,7,8
	row 3,4,5 * col 0,1,2
	row 3,4,5 * col 3,4,5
	row 3,4,5 * col 6,7,8
	row 6,7,8 * col 0,1,2
	row 6,7,8 * col 3,4,5
	row 6,7,8 * col 6,7,8
	*/
	return 
		hasSquareDuplicateHelper(0,3,0,3) ||
		hasSquareDuplicateHelper(0,3,3,6) ||
		hasSquareDuplicateHelper(0,3,6,9) ||
		hasSquareDuplicateHelper(3,6,0,3) ||
		hasSquareDuplicateHelper(3,6,3,6) ||
		hasSquareDuplicateHelper(3,6,6,9) ||
		hasSquareDuplicateHelper(6,9,0,3) ||
		hasSquareDuplicateHelper(6,9,3,6) ||
		hasSquareDuplicateHelper(6,9,6,9);
}

bool Board::full() const {
	for (int row = 0; row < BOARD_SIZE; row++) {
		for (int col = 0; col < BOARD_SIZE; col++) {
			if (board[row][col] == 0) {
				return false;
			}
		}
	}
	return true;
}

void Board::insert(int val, int row, int col) {
	if (board[row][col] != 0) {
		throw NumException();
	}
	if (val < 0 || val > 9) {
		throw ValException();
	}
	if (row < 0 || row >= BOARD_SIZE) {
		throw RowException();
	}
	if (col < 0 || col >= BOARD_SIZE) {
		throw ColException();
	}
	
	board[row][col] = val;
	
	if (hasRowDuplicate()) {
		board[row][col] = 0;
		throw RowNumException();
	}
	else if (hasColDuplicate()) {
		board[row][col] = 0;
		throw ColNumException();
	}
	else if (hasSquareDuplicate()) {
		board[row][col] = 0;
		throw SquareException();
	}
}

string Board::out() const {
	string out = "";
	for (int row = 0; row < BOARD_SIZE; row++) {
		for (int col = 0; col < BOARD_SIZE; col++) {
			out += to_string(board[row][col]) + " ";
		}
	}
	return out;
}