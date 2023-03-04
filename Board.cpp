#include "Board.h"
using namespace std;

Board::Board(int size) {
	//int count = 1; // debug
	setSize(size);
	board = new int[size * size];
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			*at(row, col) = 0;
			
			//DEBUG:
			//*at(row, col) = count;
			//count++;
		}
	}
}

Board::Board(int size, ifstream& in) {
	setSize(size);
	board = new int[size * size];
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			
			in >> *at(row, col);

			//DEBUG:
			//*at(row, col) = count;
			//count++;
		}
	}
}

void Board::setSize(int size) {
	this->size = size;
}

//print the 2d array
void Board::print() {
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			if (*at(row, col) == 0) {
				cout << ". ";
			}
			else {
				cout << *at(row, col) << " ";
			}
			
		}
		cout << endl;
	}
}

int* Board::at(int row, int col) {
	return board + row * size + col;
}

bool Board::isValid() const {
	
	
	return false;
}

Board::~Board() {
	delete[] board;
}