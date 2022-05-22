#include "Board.h"
#include <iostream>

Board::Board()
{
	piece = new Piece * *[8];
	for (int i = 0; i < 8; i++) 
	{
		piece[i] = new Piece * [8];
		for (int x = 0; x < 8; x++)
		{
			piece[i][x] = nullptr;
		}
	}
	// Tu ulozuc plansze
	
	piece[0][0] = new Rock(0);
	piece[1][0] = new Knight(0);
	piece[2][0] = new Bishop(0);
	piece[3][0] = new Queen(0);
	piece[4][0] = new King(0);
	piece[5][0] = new Bishop(0);
	piece[6][0] = new Knight(0);
	piece[7][0] = new Rock(0);

	for (int i = 0; i < 8; i++) { piece[i][1] = new Pawn(0); }

	piece[0][7] = new Rock(1);
	piece[1][7] = new Knight(1);
	piece[2][7] = new Bishop(1);
	piece[3][7] = new Queen(1);
	piece[4][7] = new King(1);
	piece[5][7] = new Bishop(1);
	piece[6][7] = new Knight(1);
	piece[7][7] = new Rock(1);

	for (int i = 0; i < 8; i++) { piece[i][6] = new Pawn(1); }

	
	

	//std::cout<<p->get_type();
}

Piece* Board::get_piece(int x, int y)
{
	return piece[x][y];
}