#include "Board_screen.h"

sf::Texture* Board_screen::get_piece_txt(Piece* p)
{
    if (p->get_side() == 0)
    {
        switch (p->get_type())
        {
        case 'p':
            return &p0_t;
            break;
        case 'N':
            return &n0_t;
            break;
        case 'B':
            return &b0_t;
            break;
        case 'R':
            return &r0_t;
            break;
        case 'Q':
            return &q0_t;
            break;
        case 'K':
            return &k0_t;
            break;
        }
    }
    else
    {
        if (p->get_side() == 1)
        {
            switch (p->get_type())
            {
            case 'p':
                return &p1_t;
                break;
            case 'N':
                return &n1_t;
                break;
            case 'B':
                return &b1_t;
                break;
            case 'R':
                return &r1_t;
                break;
            case 'Q':
                return &q1_t;
                break;
            case 'K':
                return &k1_t;
                break;
            }
        }
    }
}

Board_screen::Board_screen(sf::RenderWindow& w)
{
    //std::vector < sf::RectangleShape > kaf;
    sf::RectangleShape kaf[8][8];

    std::cout << "abc";
    sf::Color col;
    col = sf::Color::Blue;

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

    if (!pressed_tex.loadFromFile("img\\Selected1.png", sf::IntRect(0, 0, 100, 100)))
    {
        std::cout << "reeeerrr";
        // error...
    }

    //load pieces tex
    p0_t.loadFromFile("img\\p0.png", sf::IntRect(0, 0, 100, 100));
    p1_t.loadFromFile("img\\p1.png", sf::IntRect(0, 0, 100, 100));
    n0_t.loadFromFile("img\\N0.png", sf::IntRect(0, 0, 100, 100));
    n1_t.loadFromFile("img\\N1.png", sf::IntRect(0, 0, 100, 100));
    b0_t.loadFromFile("img\\B0.png", sf::IntRect(0, 0, 100, 100));
    b1_t.loadFromFile("img\\B1.png", sf::IntRect(0, 0, 100, 100));
    r0_t.loadFromFile("img\\R0.png", sf::IntRect(0, 0, 100, 100));
    r1_t.loadFromFile("img\\R1.png", sf::IntRect(0, 0, 100, 100));
    q0_t.loadFromFile("img\\Q0.png", sf::IntRect(0, 0, 100, 100));
    q1_t.loadFromFile("img\\Q1.png", sf::IntRect(0, 0, 100, 100));
    k0_t.loadFromFile("img\\K0.png", sf::IntRect(0, 0, 100, 100));
    k1_t.loadFromFile("img\\K1.png", sf::IntRect(0, 0, 100, 100));


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

            //("x: " + std::to_string(x) + " y " + std::to_string(y));
            np[x][y].setString(y_to_ch(x)+std::to_string(y+1));
            np[x][y].setFont(*font); // font is a sf::Font
            np[x][y].setCharacterSize(15);
            np[x][y].setFillColor(sf::Color::Black);
            np[x][y].setStyle(sf::Text::Bold);
            np[x][y].setPosition(50 + (100 * x), 750 - (y * 100));//(50+(100*x), 50 + (y * 100));
            //std::cout << np.getPosition().x << '\n';
            field[x][y] = new Button(kaf[x][y], np[x][y]);

            movie_weeb[x][y].setTexture(movie_tex);
            movie_weeb[x][y].setPosition(sf::Vector2f(50 + (x * 100), 750 - (100 * y)));

            if (board.get_piece(x, y) != nullptr)
            {
                pieces[x][y].setTexture(*get_piece_txt(board.get_piece(x, y)));
                pieces[x][y].setPosition(sf::Vector2f(50 + (x * 100), 750 - (100 * y)));
            }
        }
    }

    checked.x = -1;
    checked.y = -1;

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
            //akt bier


            //std::cout << "EVENT borad cren\n";
            basic_events(event, w);

            if (event.type == sf::Event::MouseButtonPressed)
            {
                //std::cout << "pressed\n";
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    for (int y = 0; y < 8; y++)
                    {
                        for (int x = 0; x < 8; x++)
                        {
                            
                            field[x][y]->chState(w);
                            //std::cout << field[x][y]->getstate();// x HALOOOO y \n";
                            if (field[x][y]->getstate() == "pressed") 
                            {
                                pressed.x = x;
                                pressed.y = y;

                                /*for (int y1 = 0; y1 < 8; y1++)
                                {
                                    for (int x1 = 0; x1 < 8; x1++)
                                    {
                                        possible_movie[x1][y1] = false;
                                    }
                                }*/

                                if ((board.get_possible_movie(pressed.x,pressed.y)==true)&&(checked.x!=-1)) {

                                    board.move(checked.x, checked.y, pressed.x, pressed.y);
                                    pieces[x][y].setTexture(*get_piece_txt(board.get_piece(x, y)));
                                    pieces[x][y].setPosition(sf::Vector2f(50 + (x * 100), 750 - (100 * y)));
                                    movie_weeb[checked.x][checked.y].setTexture(movie_tex);
                                    checked.x = -1;
                                    checked.y = -1;

                                    y = 8;
                                    board.reset_possible_movies();

                                    board.next_round();
                                    break;
                                    //move
                                    //break
                                }

                                board.reset_possible_movies();

                                if ((pressed == checked)||(board.get_piece(pressed.x,pressed.y)==nullptr)||
                                    (board.get_piece(pressed.x, pressed.y)->get_side() == board.get_round() % 2))
                                {
                                    movie_weeb[checked.x][checked.y].setTexture(movie_tex);
                                    checked.x = -1;
                                    checked.y = -1;
                                    y = 8;
                                    break;
                                }

                                if (checked.x != -1) { movie_weeb[checked.x][checked.y].setTexture(movie_tex); }// if to zabezp 
                                //przed 1 razem, nadaj poprzedniemu standard tekst

                                checked.x = x;
                                checked.y = y;

                                movie_weeb[x][y].setTexture(pressed_tex);
                                
                                board.set_possible_movies(pressed.x, pressed.y);//x , y
        
                                

                                //std::cout << std::to_string(x)+" "+std::to_string(y);

                                // Tutaj funkcja ustawienie na movie_weeb mo¿liwe ruchy czyli possible_movies()
                                // funkcja zedytuje possible movie [8][8] na 1(ruch) lub 0(brak mozliwosci ruchu)
                                // potem przy wykonianu ruchu, sprawdza czy na miejscu byla bierka i dokonuje bicia
                                //
                                //possible_movie[x][y + 1] = true;
                            }
                        }
                    }
                    /*std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;*/
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
                if (board.get_piece(x, y) != nullptr) 
                {
                    //std::cout << board.get_piece(x,y)->get_type();
                    w.draw(pieces[x][y]);
                }
                

                
            }
        }
        //std::cout << "hoj\n";

        for (int y = 0; y < 8; y++)
        {
            for (int x = 0; x < 8; x++)
            {
                if (board.get_possible_movie(x,y) == true)
                {
                    w.draw(movie_weeb[x][y]);
                }
                else if (sf::Vector2i(x,y) == checked)
                {
                    w.draw(movie_weeb[x][y]);
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