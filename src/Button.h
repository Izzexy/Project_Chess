#include <SFML/Graphics.hpp>
#include <iostream>


class Button
{
	sf::RectangleShape rect;
	sf::Text text;
	std::string state;

public:
	Button(sf::RectangleShape rect_, sf::Text text_);

	void gets();

	sf::RectangleShape* getRect();

	void chState(sf::RenderWindow& window);

	std::string getstate();

	void display(sf::RenderWindow& window);
};