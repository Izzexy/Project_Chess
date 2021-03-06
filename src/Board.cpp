#include "Board.h"
#include <iostream>

Board::Board()
{
	possible_move = new bool* [8];
	piece = new Piece * *[8];
	for (int i = 0; i < 8; i++) 
	{
		piece[i] = new Piece * [8];
		possible_move[i] = new bool[8];
		for (int x = 0; x < 8; x++)
		{
			piece[i][x] = nullptr;
			possible_move[i][x] = false;
		}
	}
	// Tu ulozuc plansze
	
	piece[7][1] = new Rock(7, 1, 0);
	//piece[0][0]->set_x(0);
	//piece[0][0]->set_y(0);
	piece[1][0] = new Knight(1, 0, 1);
	piece[2][0] = new Bishop(2,0,0);
	piece[3][0] = new Queen(3,0,0);
	piece[4][0] = new King(4,0,0);
	piece[5][0] = new Bishop(5,0,0);
	piece[6][0] = new Knight(6,0,0);
	piece[7][0] = new Rock(7,0,0);
	//piece[7][0]->set_x(7);
	//piece[7][0]->set_y(0);

	for (int i = 0; i < 8; i++) 
	{ 
		piece[i][1] = new Pawn(i, 1, 0);
		/*piece[i][2]->set_x(i);
		piece[i][2]->set_y(2);*/
	}

	piece[5][1] = new Rock(5, 1, 1);
	piece[1][7] = new Knight(1, 7, 1);
	piece[7][2] = new Bishop(7, 2, 1);
	piece[3][7] = new Queen(3, 7, 1);
	piece[4][7] = new King(4, 7, 1);
	piece[5][7] = new Bishop(5, 7, 1);
	piece[6][7] = new Knight(6, 7, 1);
	piece[7][7] = new Rock(7, 7, 1);

	for (int i = 0; i < 8; i++) { piece[i][6] = new Pawn(i, 6, 1); }

	piece[0][6] = new Bishop(0, 6, 0);
	piece[0][2] = nullptr;

	
	round = 1;

	//std::cout<<p->get_type();
}

Piece* Board::get_piece(int x, int y)
{
	return piece[x][y];
}

int Board::get_round()
{
	return round;
}

void Board::set_possible_movies(int x, int y)
{
	get_piece(x, y)->possible_move(piece, possible_move);
	
}

void Board::reset_possible_movies()
{
	for (int i = 0; i < 8; i++)
	{
		for (int x = 0; x < 8; x++)
		{		
			possible_move[i][x] = false;
		}
	}
}

bool Board::get_possible_movie(int x, int y)
{
	return possible_move[x][y];
}

void Board::move(int x, int y, int xm, int ym)
{
	if (piece[xm][ym] != nullptr)
	{
		delete piece[xm][ym];
	}

	piece[xm][ym] = piece[x][y];
	piece[xm][ym]->set_x(xm);
	piece[xm][ym]->set_y(ym);
	piece[x][y] = nullptr;
}

void Board::next_round()
{
	round++;
}