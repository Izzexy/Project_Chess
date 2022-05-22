#include <iostream>
#include "Board_screen.h"

//
//int main()
//{
//
//	//Board w klasie "okno gry" w oknie potencjalnie bedzie tablica dostepnych, wybrana aktualnie biuerka(x, y)
//	//std::cout << "abca";
//	return 0;
//}

void basic_events(sf::Event& e, sf::RenderWindow& w)
{
    //std::cout << "ahoj1";
    if (e.type == sf::Event::Closed)
    {
        std::cout << "ahoj";
        w.close();
    }
}

std::string window_state;
static sf::Font font;
int main()
{
    Board aaa;
    sf::Text t;
    sf::Texture a;
    sf::Font b;
    sf::RenderWindow window(sf::VideoMode(1100, 900), "Project Chess");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);


    sf::Font font;


    // Load it from a file
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "jukagaaaaaaaaaaaaaaaaaaaaa\n";
    }
    sf::Text np;
    np.setString("aasda");
    np.setFont(font); // font is a sf::Font
    np.setCharacterSize(15);
    np.setFillColor(sf::Color::White);
    np.setStyle(sf::Text::Bold);
    np.setPosition(50 + (100 ), 50 + (100));




    Board_screen bos(window);
    while (window.isOpen())
    {
        /*sf::Event event;
        window.pollEvent(event);
        while (window.pollEvent(event))
        {
            basic_events(event, window);
        }*/
        bos.play(window, basic_events);
       /* window.clear();
        window.draw(np);
        window.display();*/
    }

    return 0;
}