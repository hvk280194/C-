#include "Board.h"
#include <iostream>

void Board::initialize() {
	mark_ = 'X';
	int digit = 1;

	for (int line = 0; line < MY_SIZE; line++) {
		for (int column = 0; column < MY_SIZE; column++) {
			board_[line][column] = DIGITS[digit++];
		}
	}
}

void Board::draw() {
	for (int line = 0; line < MY_SIZE; line++) {
		for (int column = 0; column < MY_SIZE; column++) {
			std::cout << "| " << board_[line][column] << " ";
		}
		std::cout << "| \n";
	}
}

bool Board::check() {

	int i = 0;
	int j = 0;

	for (auto i = 0; i < 3; i++) {
		j = 0;
		if (board_[i][j] == board_[i][++j] && board_[i][j] == board_[i][++j])
			return true;	
	}
	for (auto j = 0; j < 3; j++) {
		i = 0;
		if (board_[i][j] == board_[++i][j] && board_[i][j] == board_[++i][j])
			return true;
	}

	i = 0;
	j = 0;
	if (board_[i][j] == board_[++i][++j] && board_[i][j] == board_[++i][++j])
		return true;
}

bool Board::update(int position) {
	bool updated = false;

	for (int line = 0; line < MY_SIZE; line++) {
		for (int column = 0; column < MY_SIZE; column++) {
			if (board_[line][column] == DIGITS[position]) {
				board_[line][column] = mark_;
				updated = true;
			}
		}
	}

	if (updated) {
		if (mark_ == 'X')
			mark_ = 'O';
		else
			mark_ = 'X';
		
	}
	return updated;
}
