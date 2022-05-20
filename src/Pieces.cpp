#include "Pieces.h"
#include <iostream>




int Piece::get_movies()
{
	return movies;
}

char Piece::get_type()
{
	return type;
}



bool Pawn::possible_move(int x, int y, Piece*** board)
{
	return 0;
}

bool Pawn::possible_capture(int x, int y, Piece*** board)
{
	return 1;
}

//char Pawn::get_type(){return type;}

//Knight::Knight()
//{
//	type = 'K';
//	movies = 10;
//}

bool Knight::possible_move(int x, int y, Piece*** board)
{
	return 0;
}

bool Knight::possible_capture(int x, int y, Piece*** board)
{
	return 1;
}

//char Knight::get_type(){return type;}


//Bishop::Bishop()
//{
//	type = 'B';
//}
bool Bishop::possible_move(int x, int y, Piece*** board)
{
	return 0;
}

bool Bishop::possible_capture(int x, int y, Piece*** board)
{
	return 1;
}

//char Bishop::get_type() { return type; }


