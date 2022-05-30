#include "Pieces.h"


int Piece::get_movies()
{
	return movies;
}

char Piece::get_type()
{
	return type;
}
bool Piece::get_side()
{
	return side;
}
void Piece::set_x(int x_)
{
	x = x_;
}
void Piece::set_y(int y_)
{
	y = y_;
}


//Pawn::Pawn(bool side_)
//{
//	type = 'p';
//	side = side_;
//}
void Pawn::move(bool mov[8][8], Piece*** board, bool* check)
{

}

void Pawn::possible_move(Piece*** board, bool** possible_mov)
{
	//Piece* copy; //= new Piece(board[x][y]);
	//
	//copy = board[x][y+1];

	////sprawdz czy nie bije krola, swojego lub poza zakres
	//board[x][y + 1] = copy;
	//board[x][y] = nullptr;//board[x][y + 1];

	Piece* copy; //= new Piece(board[x][y]);

	
	if (y + 1 > 7)
	{
		return;
	}
	copy = board[x][y + 1];

		//sprawdz czy nie bije krola, swojego lub poza zakres
	board[x][y + 1] = board[x][y];
	board[x][y] = nullptr;//board[x][y + 1];

	board[x][y] = board[x][y + 1];
	board[x][y + 1] = copy;

		//sprawdzanko

	possible_mov[x][y + 1] = true;
	

	//sprawdzenie poprawnosci
	if (true)
	{
		return;
	}
	else
	{
		board[x][y + 1] = board[x][y];
		board[x][y] = copy;
	}


	std::cout << "pawn posm";
	return;
}

bool Pawn::possible_capture(int x, int y, Piece*** board)
{
	return 1;
}

//char Pawn::get_type(){return type;}

//Knight::Knight()
//{
//	type = 'K';
//	movies = 10;
//}
//
//Knight::Knight(bool side_)
//{
//	type = 'N';
//	side = side_;
//}

void Knight::move(bool mov[8][8], Piece*** board, bool* check)
{

}

void Knight::possible_move(Piece*** board, bool** possible_mov)
{
	
}

bool Knight::possible_capture(int x, int y, Piece*** board)
{
	return 1;
}

//char Knight::get_type(){return type;}


//Bishop::Bishop()
//{
//	type = 'B';
//}
//Bishop::Bishop(bool side_)
//{
//	type = 'B';
//	side = side_;
//}

void Bishop::move(bool mov[8][8], Piece*** board, bool* check)
{
	for (int xm = x - 1, ym = y - 1; ((xm > -1) && (ym > -1)); xm--, ym--)
	{
		if (board[xm][ym] != nullptr)
		{
			if ((board[xm][ym]->get_side() == side) || (board[xm][ym]->get_type() == 'K'))
			{
				if ((board[xm][ym]->get_type() == 'K') && (board[xm][ym]->get_side() != side)) *check = 1;
				break;
			}
			else
			{
				mov[xm][y] = true;
				break;
			}
		}


		mov[xm][y] = true;

	}
}

void Bishop::possible_move(Piece*** board, bool** possible_mov)
{
}

bool Bishop::possible_capture(int x, int y, Piece*** board)
{
	return 1;
}

//Rock::Rock(bool side_)
//{
//	type = 'R';
//	side = side_;
//}

void Rock::move(bool mov[8][8], Piece*** board, bool* check) /// piece*** na board nie?
{
	for (int xm = x+1; xm < 8; xm++)
	{
		if (board[xm][y] != nullptr)
		{
			if ((board[xm][y]->get_side() == side) || (board[xm][y]->get_type() == 'K'))
			{
				if ((board[xm][y]->get_type() == 'K') &&(board[xm][y]->get_side() != side)) *check = 1;
				break;
			}
			else
			{
				mov[xm][y] = true;
				break;
			}
		}
		
		
		mov[xm][y] = true;
		
	}

	for (int xm = x-1; xm > -1; xm--)
	{
		if (board[xm][y] != nullptr)
		{
			if ((board[xm][y]->get_side() == side) || (board[xm][y]->get_type() == 'K'))
			{
				if ((board[xm][y]->get_type() == 'K') && (board[xm][y]->get_side() != side)) *check = 1;
				break;
			}
			else
			{
				mov[xm][y] = true;
				break;
			}
		}

		mov[xm][y] = true;
	}

	for (int ym = 1+ y; ym < 8; ym++)
	{
		if (board[x][ym] != nullptr)
		{
			if ((board[x][ym]->get_side() == side) || (board[x][ym]->get_type() == 'K'))
			{
				if ((board[x][ym]->get_type() == 'K') && (board[x][ym]->get_side() != side))*check = 1;
				break;
			}
			else
			{
				mov[x][ym] = true;
				break;
			}
		}

		mov[x][ym] = true;
	}

	for (int ym = y-1; ym >-1; ym--)
	{
		if (board[x][ym] != nullptr)
		{
			if ((board[x][ym]->get_side() == side) || (board[x][ym]->get_type() == 'K'))
			{
				if ((board[x][ym]->get_type() == 'K')&&(board[x][ym]->get_side() != side))*check = 1;
				break;
			}
			else
			{
				mov[x][ym] = true;
				break;
			}
		}

		mov[x][ym] = true;
	}
}

void Rock::possible_move(Piece*** board, bool** possible_mov)/// piece*** na board nie?
{
	Piece* copy; //= new Piece(board[x][y]);

	//dodaj funkcje movie w piece, zwroci wszystkie ruchy z danej pozycji(w pró¿ni)
	// i zwróci do tablicy possible_mov, potem tablica zostaje przefiltrowanya przez kolizje i szachy
	bool m[8][8] = { false };
	move(m, board);

	for (int ym = 0; ym < 8; ym++) //(int yp = 1; yp + y < 8; yp++)
	{
		for (int xm = 0; xm < 8; xm++)
		{
			if (m[xm][ym] == false)continue;

			/*if (board[xm][ym] == nullptr)
			{
				possible_mov[xm][ym] = true;
				continue;
			}*/
			//(board[x][y + yp]->get_side() == side) ||
			//if ((board[xm][ym]->get_type() == 'K'))  // zatrzymaj przed swoim
			//{
			//	break;
			//}
			//else if ((board[xm][ym- 1] != nullptr) && (board[xm][ym- 1]->get_side() != side)) // zatrzymaj na przeciwniku
			//{
			//	break;
			//}



			copy = board[xm][ym];

			//sprawdz czy nie bije krola, swojego lub poza zakres
			std::cout << board[x][y] << "  " << board[xm][ym] << '\n';

			board[xm][ym] = board[x][y];
			board[x][y] = nullptr;//board[x][y + 1];

			std::cout << board[x][y] << "  " << board[xm][ym] << '\n';

			//sprawdzanko szacha 
			//jezeli dobrze to posssible mov = true
			for (int y_chm = 0; y_chm < 8; y_chm++)
			{
				for (int x_chm = 0; x_chm < 8; x_chm++)
				{
					if ((board[x_chm][y_chm] == nullptr) || (board[x_chm][y_chm]->get_side() == side))
					{
						continue;
					}
					

					bool trash[8][8] = { false };
					bool* ch = new bool{ 0 };
					std::cout << x_chm<<"  "<<y_chm<<'\n';

					board[x_chm][y_chm]->move(trash, board, ch);
					if (*ch == 0)
					{
						possible_mov[xm][ym] = true;
					}
					else
					{
						possible_mov[xm][ym] = false;
						y_chm = 8;
						break;
					}

					delete ch;
				}
			}
			//{possible_mov[xm][ym] = true; }

			board[x][y] = board[xm][ym];
			board[xm][ym] = copy;

			std::cout << board[x][y] << "  " << board[xm][ym] << '\n';

		}
	}

	//sprawdzenie poprawnosci
	if (true)
	{
		return;
	}
	else
	{
		board[x][y + 1] = board[x][y];
		board[x][y] = copy;
	}

	delete copy;
}

bool Rock::possible_capture(int x, int y, Piece*** board)
{
	return 1;
}

//Queen::Queen(bool side_)
//{
//	type = 'Q';
//	side = side_;
//}

void Queen::move(bool mov[8][8], Piece*** board, bool* check)
{

}

void Queen::possible_move(Piece*** board, bool** possible_mov)
{

}

bool Queen::possible_capture(int x, int y, Piece*** board)
{
	return 1;
}

//King::King(bool side_)
//{
//	type = 'K';
//	side = side_;
//}

void King::move(bool mov[8][8], Piece*** board, bool* check)
{

}

void King::possible_move(Piece*** board, bool** possible_mov)
{

}

bool King::possible_capture(int x, int y, Piece*** board)
{
	return 1;
}

void None::possible_move(Piece*** board, bool** possible_mov)
{
	return;
}
bool None::possible_capture(int x, int y, Piece*** board)
{
	return 0;
}

//char Bishop::get_type() { return type; }


