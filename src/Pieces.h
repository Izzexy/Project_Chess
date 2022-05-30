#include <iostream>

class Piece
{
protected:
	//static const char type;
	int x;
	int y;
	char type = 'n';
	int movies = 0;
	bool side; // 0 = white ||| 1 = blac
public:
	Piece(int x_, int y_, bool side_) : x(x_), y(y_), side(side_){}

	virtual void move(bool mov[8][8], Piece*** board, bool* check = nullptr) = 0;

	virtual void possible_move(Piece*** board, bool** possible_mov) = 0;// w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	virtual bool possible_capture(int x, int y, Piece*** board) = 0;// @up
	//virtual char get_type() = 0;
	//virtual void Promotion ->>>>>>>>>>>>dodaj!! czyli zmiana type!!!!
	void set_x(int x_);
	void set_y(int y_);
	int get_movies();
	char get_type();
	bool get_side();
};

class Pawn :public Piece
{
	//static const char type = 'P';
	void move(bool mov[8][8], Piece*** board, bool* check = nullptr);
public:
	Pawn(int x_, int y_, bool side_) : Piece(x_, y_, side_) {
		type = 'p';
	}
	void possible_move(Piece*** board, bool** possible_mov); // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	bool possible_capture(int x, int y, Piece*** board);// @up
};

class Knight :public Piece
{
	//static const char type = 'K';
public:
	void move(bool mov[8][8], Piece*** board, bool* check = nullptr);
	Knight(int x_, int y_, bool side_) : Piece(x_, y_, side_) {
		type = 'N';
	}
	void possible_move(Piece*** board, bool** possible_mov); // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	bool possible_capture(int x, int y, Piece*** board);// @up
};

class Bishop :public Piece
{
	//static const char type = 'B';
public:
	void move(bool mov[8][8], Piece*** board, bool* check = nullptr);

	Bishop(int x_, int y_, bool side_) : Piece(x_, y_, side_) {
		type = 'B';
	}
	void possible_move(Piece*** board, bool** pissible_mov); // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	bool possible_capture(int x, int y, Piece*** board);// @up
};

class Rock :public Piece
{
	//static const char type = 'B';
public:
	void move(bool mov[8][8], Piece*** board, bool* check = nullptr);

	Rock(int x_, int y_, bool side_) : Piece(x_, y_, side_) {
		type = 'R';
	}

	void possible_move(Piece*** board, bool** pissible_mov); // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	bool possible_capture(int x, int y, Piece*** board);// @up
};

class Queen :public Piece
{
	//static const char type = 'B';
public:
	void move(bool mov[8][8], Piece*** board, bool* check = nullptr);

	Queen(int x_, int y_, bool side_) : Piece(x_, y_, side_) {
		type = 'Q';
	}

	void possible_move(Piece*** board, bool** pissible_mov); // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	bool possible_capture(int x, int y, Piece*** board);// @up
};

class King :public Piece
{
	//static const char type = 'B';
public:
	void move(bool mov[8][8], Piece*** board, bool* check = nullptr);

	King(int x_, int y_, bool side_) : Piece(x_, y_, side_) {
		type = 'K';
	}

	void possible_move(Piece*** board, bool** pissible_mov); // w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	bool possible_capture(int x, int y, Piece*** board);// @up
};

class None :public Piece
{
	//static const char type = 'B';
public:
	void move(bool mov[8][8], Piece*** board, bool* check = nullptr);

	void possible_move(Piece*** board, bool** possible_mov);// w agrumencie wskaznik do tablicy, z ustawieniem bierek ---+++
	bool possible_capture(int x, int y, Piece*** board);// @up
};