#include "Pieces.h"


class Board
{
	Piece*** piece;

public:
	Board();

	Piece* get_piece(int x, int y);

	// void move( x, y, x2, y2) sprawdza czy sie da move(zarkes ruch�w w sytuacji), czy po tym m�j kr�l ma szacha , 
	// bicie, promocja, szach, mat
	// i jedze jak nie to odmowa
};