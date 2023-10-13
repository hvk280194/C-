#include <iostream>
#include "Board.h"
#include "Game.h"

int main() {
	

	Board* board = new Board();
	Game game(board);
	game.run();
	std::cin.get();
	delete board;
	
		

}