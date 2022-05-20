#include <iostream>

class Piece
{
	static const char type;
public:
	virtual bool possible_move(int x, int y) = 0; // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	virtual bool possible_capture(int x, int y) = 0;// @up
	virtual char get_type() = 0;
};

class Pawn :public Piece
{
	static const char type='p';
public:

	bool possible_move(int x, int y); // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	bool possible_capture(int x, int y);// @up
	char get_type();
};

class Knight :public Piece
{
	static const char type='K';
public:

	bool possible_move(int x, int y); // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	bool possible_capture(int x, int y);// @up
	char get_type();
};