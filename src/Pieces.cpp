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


Pawn::Pawn(bool side_)
{
	type = 'p';
	side = side_;
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

Knight::Knight(bool side_)
{
	type = 'N';
	side = side_;
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
Bishop::Bishop(bool side_)
{
	type = 'B';
	side = side_;
}

void Bishop::possible_move(Piece*** board, bool** possible_mov)
{

}

bool Bishop::possible_capture(int x, int y, Piece*** board)
{
	return 1;
}

Rock::Rock(bool side_)
{
	type = 'R';
	side = side_;
}

void Rock::possible_move(Piece*** board, bool** possible_mov)
{
	Piece* copy; //= new Piece(board[x][y]);

	for (int yp = 1; yp + y < 8; yp++)
	{
		if (board[x][y + yp] == nullptr)
		{
			possible_mov[x][y + yp] = true;
			continue;
		}
	
		if  (board[x][y + yp]->get_side() == side)  // zatrzymaj przed swoim
		{
			break;
		}

		if ((board[x][y + yp - 1]!=nullptr)&&(board[x][y + yp - 1]->get_side() != side)) // zatrzymaj na przeciwniku
		{
			break;
		}
		
		
		
		copy = board[x][y + yp];

		//sprawdz czy nie bije krola, swojego lub poza zakres
		board[x][y + yp] = board[x][y];
		board[x][y] = nullptr;//board[x][y + 1];

		board[x][y] = board[x][y + yp];
		board[x][y + yp] = copy;

		//sprawdzanko

		possible_mov[x][y + yp] = true;
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
}

bool Rock::possible_capture(int x, int y, Piece*** board)
{
	return 1;
}

Queen::Queen(bool side_)
{
	type = 'Q';
	side = side_;
}

void Queen::possible_move(Piece*** board, bool** possible_mov)
{

}

bool Queen::possible_capture(int x, int y, Piece*** board)
{
	return 1;
}

King::King(bool side_)
{
	type = 'K';
	side = side_;
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


