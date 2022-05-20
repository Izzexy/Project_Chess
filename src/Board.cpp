#include "Board.h"
#include <iostream>

Board::Board()
{
	board = new Piece * *[8];
	for (int i = 0; i < 8; i++) 
	{
		board[i] = new Piece * [8];
	}

	Piece *p;
	
	p = new Pawn();
	board[3][4] = p;

	std::cout<<p->get_type();
}