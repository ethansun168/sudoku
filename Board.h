#pragma once
#include <iostream>
#include <fstream>
#include <string>
class Board {
private:
	int size;
	int* board;
public:
	//Initialize the board to all 0's
	Board(int size);

	//Initialize the board to ifstream
	//Requires in to be well formatted (at least 81 numbers between 0 and 9)
	Board(int size, std::ifstream& in);

	//print the board to cout
	void print();

	//set the size to size
	//requires 1 <= size <= 9
	void setSize(int size);

	//return a pointer to board[row][col]
	//*at(row, col) = value;
	//to set the value at that index
	int* at(int row, int col);

	//checks if the board is a valid sudoku board
	//if one square is empty, return false
	bool isValid() const;

	//destructor - deallocate board pointer from dynamic memory
	~Board();
};
