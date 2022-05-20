#include <iostream>

class Piece
{
protected:
	//static const char type;
	int x = -1;
	int y = -1;
	char type = 'n';
	int movies =  0;
	bool side = -1; // 0 = white ||| 1 = black
public:

	virtual bool possible_move(int x, int y, Piece*** board) = 0; // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	virtual bool possible_capture(int x, int y, Piece*** board) = 0;// @up
	//virtual char get_type() = 0;
	//virtual void Promotion ->>>>>>>>>>>>dodaj!! czyli zmiana type!!!!
	int get_movies();
	char get_type();
};

class Pawn :public Piece
{
	//static const char type = 'P';
public:
	Pawn()
	{
		type = 'P';
	}

	bool possible_move(int x, int y, Piece*** board); // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	bool possible_capture(int x, int y, Piece*** board);// @up
};

class Knight :public Piece
{
	//static const char type = 'K';
public:
	Knight()
	{
		type = 'K';
	}

	bool possible_move(int x, int y, Piece*** board); // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	bool possible_capture(int x, int y, Piece*** board);// @up
};

class Bishop :public Piece
{
	//static const char type = 'B';
public:
	Bishop()
	{
		type = 'B';
	}

	bool possible_move(int x, int y, Piece*** board); // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	bool possible_capture(int x, int y, Piece*** board);// @up
};