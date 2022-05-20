#include "Pieces.h"
#include <iostream>



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


