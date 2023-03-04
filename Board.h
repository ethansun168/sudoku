#pragma once
#include <iostream>
#include <fstream>
#include <string>
class Board {
private:
	int size;
	int* board;
public:
	Board(int size);
	Board(int size, std::ifstream& in);
	void print();
	void setSize(int size);
	int* at(int row, int col);
	~Board();
};
