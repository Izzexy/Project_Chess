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
bool Piece::get_side()
{
	return side;
}


Pawn::Pawn(bool side_)
{
	type = 'p';
	side = side_;
}

void Pawn::possible_move(int x, int y, Piece*** board, bool** possible_mov)
{
	std::cout << "pawn posm";
	return;
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

Knight::Knight(bool side_)
{
	type = 'N';
	side = side_;
}

void Knight::possible_move(int x, int y, Piece*** board, bool** possible_mov)
{
	
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
Bishop::Bishop(bool side_)
{
	type = 'B';
	side = side_;
}

void Bishop::possible_move(int x, int y, Piece*** board, bool** possible_mov)
{
	
}

bool Bishop::possible_capture(int x, int y, Piece*** board)
{
	return 1;
}

Rock::Rock(bool side_)
{
	type = 'R';
	side = side_;
}

void Rock::possible_move(int x, int y, Piece*** board, bool** possible_mov)
{

}

bool Rock::possible_capture(int x, int y, Piece*** board)
{
	return 1;
}

Queen::Queen(bool side_)
{
	type = 'Q';
	side = side_;
}

void Queen::possible_move(int x, int y, Piece*** board, bool** possible_mov)
{

}

bool Queen::possible_capture(int x, int y, Piece*** board)
{
	return 1;
}

King::King(bool side_)
{
	type = 'K';
	side = side_;
}

void King::possible_move(int x, int y, Piece*** board, bool** possible_mov)
{

}

bool King::possible_capture(int x, int y, Piece*** board)
{
	return 1;
}

void None::possible_move(int x, int y, Piece*** board, bool** possible_mov)
{
	return;
}
bool None::possible_capture(int x, int y, Piece*** board)
{
	return 0;
}

//char Bishop::get_type() { return type; }


