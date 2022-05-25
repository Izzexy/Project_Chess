#include "Board.h"
#include <iostream>

Board::Board()
{
	possible_movie = new bool* [8];
	piece = new Piece * *[8];
	for (int i = 0; i < 8; i++) 
	{
		piece[i] = new Piece * [8];
		possible_movie[i] = new bool[8];
		for (int x = 0; x < 8; x++)
		{
			piece[i][x] = nullptr;
			possible_movie[i][x] = false;
		}
	}
	// Tu ulozuc plansze
	
	piece[0][0] = new Rock(0);
	piece[0][0]->set_x(0);
	piece[0][0]->set_y(0);
	piece[1][0] = new Knight(0);
	piece[2][0] = new Bishop(0);
	piece[3][0] = new Queen(0);
	piece[4][0] = new King(0);
	piece[5][0] = new Bishop(0);
	piece[6][0] = new Knight(0);
	piece[7][0] = new Rock(0);
	piece[7][0]->set_x(7);
	piece[7][0]->set_y(0);

	for (int i = 0; i < 8; i++) { piece[i][1] = new Pawn(0);
	piece[i][1]->set_x(i);
	piece[i][1]->set_y(1);
	}

	piece[0][7] = new Rock(1);
	piece[1][7] = new Knight(1);
	piece[2][7] = new Bishop(1);
	piece[3][7] = new Queen(1);
	piece[4][7] = new King(1);
	piece[5][7] = new Bishop(1);
	piece[6][7] = new Knight(1);
	piece[7][7] = new Rock(1);

	for (int i = 0; i < 8; i++) { piece[i][6] = new Pawn(1); }

	
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
	get_piece(x, y)->possible_move(piece, possible_movie);
}

void Board::reset_possible_movies()
{
	for (int i = 0; i < 8; i++)
	{
		for (int x = 0; x < 8; x++)
		{		
			possible_movie[i][x] = false;
		}
	}
}

bool Board::get_possible_movie(int x, int y)
{
	return possible_movie[x][y];
}