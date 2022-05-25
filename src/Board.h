#include "Pieces.h"


class Board
{
	Piece*** piece;
	int round;
	bool** possible_movie;

public:
	Board();

	//void move_piece(sf::Vector2i p);
	Piece* get_piece(int x, int y);
	int get_round();
	void set_possible_movies(int x, int y);
	void reset_possible_movies();
	bool get_possible_movie(int x, int y);

	// void move( x, y, x2, y2) sprawdza czy sie da move(zarkes ruchów w sytuacji), czy po tym mój król ma szacha , 
	// bicie, promocja, szach, mat
	// i jedze jak nie to odmowa
	// przy sprawdzaniu skopiuj piece(statycznie) i sprawdz na tym potem kopia nba oryginal, inaczej 
	//beda problemy lub zrob backup odpowiednich bierek
};