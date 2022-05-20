#include "Pieces.h"
#include <iostream>


int Piece::get_movies()
{
	return movies;
}


Pawn::Pawn()
{
	//movies++;
}

bool Pawn::possible_move(int x, int y)
{
	return 0;
}

bool Pawn::possible_capture(int x, int y)
{
	return 1;
}

char Pawn::get_type(){return type;}

bool Knight::possible_move(int x, int y)
{
	return 0;
}

bool Knight::possible_capture(int x, int y)
{
	return 1;
}

char Knight::get_type(){return type;}

bool Bishop::possible_move(int x, int y)
{
	return 0;
}

bool Bishop::possible_capture(int x, int y)
{
	return 1;
}

char Bishop::get_type() { return type; }


