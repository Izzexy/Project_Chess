#include "Button.h"

Button::Button(sf::RectangleShape rect_, sf::Text text_)// by text
{
	rect = rect_;
	text = text_;
	state = "off";

	rect.setPosition(text.getPosition());
	//text.setCharacterSize(rect_.getPosition().x-2);
	std::string a = text.getString();

	std::cout << a <<'\n';
	//rect->setSize(sf::Vector2f(text.getLocalBounds().width + 10, text.getCharacterSize() + 10));
	rect.setSize(sf::Vector2f(100, 100));
	rect.move(sf::Vector2f(0, 0));
}

void Button::gets()
{
	std::cout << rect.getPosition().x << '\n';
	std::cout << rect.getPosition().y << '\n';
	std::cout << rect.getScale().x << '\n';
	std::cout << rect.getScale().y << '\n';
	std::cout << rect.getLocalBounds().height << '\n';
	std::cout << rect.getLocalBounds().width << '\n';
	std::cout << rect.getLocalBounds().top << '\n';
	std::cout << rect.getLocalBounds().left << '\n';
}

void Button::chState(sf::RenderWindow& window)
{
	if ((sf::Mouse::getPosition(window).x >= rect.getPosition().x) &&
		(sf::Mouse::getPosition(window).x <= rect.getPosition().x + rect.getLocalBounds().width) &&
		(sf::Mouse::getPosition(window).y >= rect.getPosition().y) &&
		(sf::Mouse::getPosition(window).y <= rect.getPosition().y + rect.getLocalBounds().height))
	{
		state = "hover";
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			state = "pressed";
		}

	}
	else state = "off";
}

std::string Button::getstate()
{
	return state;
}

sf::RectangleShape* Button::getRect()
{
	return &rect;
}

void Button::display(sf::RenderWindow& window)
{
	//std::cout << text.getLocalBounds().width;
	window.draw(rect);
	window.draw(text);
}