#include <iostream>

class Piece
{
protected:
	static const char type = 'n';
	int movies = 0;
public:
	virtual bool possible_move(int x, int y) = 0; // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	virtual bool possible_capture(int x, int y) = 0;// @up
	virtual char get_type() = 0;
	int get_movies();
};

class Pawn :public Piece
{
	static const char type = 'p';
public:
	Pawn();

	bool possible_move(int x, int y); // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	bool possible_capture(int x, int y);// @up
	char get_type();
};

class Knight :public Piece
{
	static const char type = 'K';
public:

	bool possible_move(int x, int y); // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	bool possible_capture(int x, int y);// @up
	char get_type();
};

class Bishop :public Piece
{
	static const char type = 'B';
	int a = 0;
public:

	bool possible_move(int x, int y); // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	bool possible_capture(int x, int y);// @up
	char get_type();
};