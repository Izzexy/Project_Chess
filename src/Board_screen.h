#include <iostream>
#include "Button.h"


class Board_screen
{
	typedef void(*Actions)(sf::Event& e, sf::RenderWindow& w);
	Button*** field;
	sf::Texture movie_tex, pressed_tex;
	sf::Sprite movie_web[8][8];
	sf::Vector2i pressed;


	//sf::RectangleShape **white_field, black_field;
public:

	Board_screen(sf::RenderWindow& w);
	void play(sf::RenderWindow& w, Actions basic_events);

	char y_to_ch(int y);
};