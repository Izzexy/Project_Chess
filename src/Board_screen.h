#include <iostream>
#include "Button.h"
#include "Board.h"

class Board_screen
{
	typedef void(*Actions)(sf::Event& e, sf::RenderWindow& w);
	Board board;
	Button*** field;
	sf::Texture movie_tex, pressed_tex, p0_t, p1_t, b0_t, b1_t, n0_t, n1_t, r0_t, r1_t, k0_t, k1_t,
		q0_t, q1_t;
	sf::Sprite movie_weeb[8][8], pieces[8][8];
	sf::Vector2i pressed;
	bool possible_movie[8][8] = { false };


	//sf::RectangleShape **white_field, black_field;
public:

	Board_screen(sf::RenderWindow& w);
	void play(sf::RenderWindow& w, Actions basic_events);

	char y_to_ch(int y);
	sf::Texture* get_piece_txt(Piece* p);
};