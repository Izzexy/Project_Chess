#include "Board.h"
#include <iostream>

Board::Board()
{
	board = new Piece * *[8];
	for (int i = 0; i < 8; i++) 
	{
		board[i] = new Piece * [8];
	}

	Pawn pawn;

	board[3][4] = &pawn;

	std::cout<<board[3][4]->possible_move(3,2);
}