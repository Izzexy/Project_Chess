#include <iostream>

class Piece
{
public:
	virtual bool possible_move(int x, int y) = 0; // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	virtual bool possible_capture(int x, int y) = 0;// @up
};

class Pawn :public Piece
{
public:
	bool possible_move(int x, int y); // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	bool possible_capture(int x, int y);// @up
};