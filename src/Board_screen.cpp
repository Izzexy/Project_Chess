#include "Board_screen.h"

Board_screen::Board_screen(sf::RenderWindow& w)
{
    //std::vector < sf::RectangleShape > kaf;
    sf::RectangleShape kaf[8][8];

    std::cout << "abc";
    sf::Color col;
    col = sf::Color::White;

    for (int i = 0; i < 8; i++)
    {
        for (int x = 0; x < 8; x++)
        {
            sf::RectangleShape a;
         
            a.setFillColor(col);
            
            a.setOutlineThickness(0);
            kaf[x][i]=a;
            if (col == sf::Color::White) col = sf::Color::Blue;
            else col = sf::Color::White;
        }
        if (col == sf::Color::White) col = sf::Color::Blue;
        else col = sf::Color::White;
    }
    /*white_field.setFillColor(sf::Color::Wh   ite);
    white_field.setOutlineThickness(0); */

   /* black_field.setFillColor(sf::Color::Green);
    black_field.setOutlineThickness(0);*/

    sf::Text np[8][8];
    sf::Font* font = new sf::Font;

    if (!movie_tex.loadFromFile("img\\image.png", sf::IntRect(0, 0, 100, 100)))
    {
        std::cout << "reeeerrr";
        // error...
    }

    if (!pressed_tex.loadFromFile("img\\image2.png", sf::IntRect(0, 0, 100, 100)))
    {
        std::cout << "reeeerrr";
        // error...
    }


    // Load it from a file
    if (!font->loadFromFile("font\\arial.ttf"))
    {
        std::cout << "jukagaaaaaaaaaaaaaaaaaaaaa\n";
    }


    field = new Button * *[8];
    for (int i = 0; i < 8; i++)
    {
        field[i] = new Button * [8];
    }

    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            np[x][y].setString(y_to_ch(x)+std::to_string(y+1));
            np[x][y].setFont(*font); // font is a sf::Font
            np[x][y].setCharacterSize(15);
            np[x][y].setFillColor(sf::Color::Black);
            np[x][y].setStyle(sf::Text::Bold);
            np[x][y].setPosition(50 + (100 * x), 750 - (y * 100));//(50+(100*x), 50 + (y * 100));
            //std::cout << np.getPosition().x << '\n';
            field[x][y] = new Button(kaf[x][y], np[x][y]);

            movie_web[x][y].setTexture(movie_tex);
            movie_web[x][y].setPosition(sf::Vector2f(50 + (100 * x), 750 - (y * 100)));
        }
    }

    pressed.x = -1;
    pressed.y = -1;

}

void Board_screen::play(sf::RenderWindow& w, Actions basic_events)
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (true)
    {
        sf::Event event;
        // window.pollEvent(event);

        while (w.pollEvent(event))
        {

            std::cout << "EVENT borad cren\n";
            basic_events(event, w);

            if (event.type == sf::Event::MouseButtonPressed)
            {
                std::cout << "pressed\n";
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    for (int y = 0; y < 8; y++)
                    {
                        for (int x = 0; x < 8; x++)
                        {
                            field[x][y]->chState(w);
                            if (field[x][y]->getstate() == "pressed") 
                            {
                                if (pressed.x != -1) { movie_web[pressed.x][pressed.y].setTexture(movie_tex); }
                                pressed.x = x;
                                pressed.y = y;
                                movie_web[x][y].setTexture(pressed_tex);
                            }
                        }
                    }
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                }
            }
            //klikniecia na kafelki
        }

        w.clear();
        
        for (int y = 0; y < 8; y++)
        {
            for (int x = 0; x < 8; x++)
            {
                field[x][y]->display(w);
            }
        }

        for (int y = 0; y < 8; y++)
        {
            for (int x = 0; x < 8; x++)
            {
                if (sf::Vector2i(x,y) == pressed)
                {
                    w.draw(movie_web[x][y]);
                }
            }
        }
        
        w.display();
    }
}

char Board_screen::y_to_ch(int y)
{
    switch (y)
    {
        case 0:
            return 'a';
            break;
        case 1:
            return 'b';
            break;
        case 2:
            return 'c';
            break;
        case 3:
            return 'd';
            break;
        case 4:
            return 'e';
            break;
        case 5:
            return 'f';
            break;
        case 6:
            return 'g';
            break;
        case 7:
            return 'h';
            break;

    }
}