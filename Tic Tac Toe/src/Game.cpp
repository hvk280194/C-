#include <iostream>
#include "Game.h"
#include<time.h>

Game::Game(Board* board):
	board_(board)
{}
void Game::run() {
	board_->initialize();
	int move = 0;
	while (move < 9) {
		std::cout << "\n Tic Tac Toe \n";
		board_->draw();
		std::cout << "\n Player " << (move % 2 == 0 ? "1" : "2") << "turn:";
		int position = 0;
		std::cin >> position;

		while (position > 9 || position < 1) {
			std::cout << "\nInvalid input. Enter new input: \n";
			std::cin >> position;
		}
		while (!board_->update(position)) {
			std::cout << "\nAlready used position. Enter not used position: \n";
			std::cin >> position;
		}

		if (move > 3) {
			if (board_->check()) {
				board_->draw();
				std::cout << "\nPlayer" << (move % 2 == 0 ? "1" : "2")<<"won!!!";
				
				break;
			}
			else if (move == 8) {
				std::cout << "\n Its a draw \n";
			}
		}
		move++;
	}

}
