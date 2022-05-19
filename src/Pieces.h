#include <iostream>

class Piece
{
	int x, y;

public:
	Piece();

	virtual bool possible_move(int x, int y) = 0; // w agrumencie wskaznik do tablicy, z ustawieniem bierek
	virtual bool possible_capture(int x, int y) = 0;// @up
};

class Pawn
	:Piece
{
public:

};