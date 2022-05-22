#include <iostream>

class Piece
{
protected:
	//static const char type;
	int x;
	int y;
	char type = 'n';
	int movies =  0;
	bool side; // 0 = white ||| 1 = black
public:

	virtual void possible_move(int x, int y, Piece*** board, bool** possible_mov) = 0;// w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	virtual bool possible_capture(int x, int y, Piece*** board) = 0;// @up
	//virtual char get_type() = 0;
	//virtual void Promotion ->>>>>>>>>>>>dodaj!! czyli zmiana type!!!!
	int get_movies();
	char get_type();
	bool get_side();
};

class Pawn :public Piece
{
	//static const char type = 'P';
public:
	Pawn(bool side_);

	void possible_move(int x, int y, Piece*** board, bool** possible_mov); // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	bool possible_capture(int x, int y, Piece*** board);// @up
};

class Knight :public Piece
{
	//static const char type = 'K';
public:
	Knight(bool side_);

	void possible_move(int x, int y, Piece*** board, bool** possible_mov); // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	bool possible_capture(int x, int y, Piece*** board);// @up
};

class Bishop :public Piece
{
	//static const char type = 'B';
public:
	Bishop(bool side_);

	void possible_move(int x, int y, Piece*** board, bool** pissible_mov); // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	bool possible_capture(int x, int y, Piece*** board);// @up
};

class Rock :public Piece
{
	//static const char type = 'B';
public:
	Rock(bool side_);

	void possible_move(int x, int y, Piece*** board, bool** pissible_mov); // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	bool possible_capture(int x, int y, Piece*** board);// @up
};

class Queen :public Piece
{
	//static const char type = 'B';
public:
	Queen(bool side_);

	void possible_move(int x, int y, Piece*** board, bool** pissible_mov); // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	bool possible_capture(int x, int y, Piece*** board);// @up
};

class King :public Piece
{
	//static const char type = 'B';
public:
	King(bool side_);

	void possible_move(int x, int y, Piece*** board, bool** pissible_mov); // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	bool possible_capture(int x, int y, Piece*** board);// @up
};

class None :public Piece
{
	//static const char type = 'B';
public:
	void possible_move(int x, int y, Piece*** board, bool** possible_mov);// w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	bool possible_capture(int x, int y, Piece*** board);// @up
};