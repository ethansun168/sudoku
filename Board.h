#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class ValException {};
class RowException {};
class ColException {};
class RowNumException {};
class ColNumException {};
class SquareException {};
class NumException {};
const int BOARD_SIZE = 9;

class Board {
private:

	int board[BOARD_SIZE][BOARD_SIZE];
	bool hasSquareDuplicateHelper(int rowStart, int rowEnd, int colStart, int colEnd) const;
public:
	//Initialize the board to all 0's
	Board();

	//Initialize the board to ifstream
	//Requires in to be well formatted (at least 81 numbers between 0 and 9)
	Board(std::ifstream& in);

	//print the board to cout
	void print();

	/*
	effect: returns true if the board is full and false otherwise
	*/
	bool full() const;

	/*
	effect: returns true if the board has duplicates in a row
	*/
	bool hasRowDuplicate() const;

	/*
	effect: effect: returns true if the board has duplicates in a col
	*/
	bool hasColDuplicate() const;

	/*
	effect: effect: returns true if the board has duplicates in a square
	*/
	bool hasSquareDuplicate() const;

	/*
	modifies: board
	effect: inserts val at row and col
		throws NumException if there is already a number in row and col
		throws ValException, RowException, or ColException if conditions are not met
			checks if 0 <= row < BOARD_SIZE, 0 <= col < BOARD_SIZE, 1 <= val <= 9
		throws RowNumException, ColNumException, or SquareException if there are duplicates
		
	*/
	void insert(int val, int row, int col);

	//returns the numbers as a string
	std::string out() const;
};
