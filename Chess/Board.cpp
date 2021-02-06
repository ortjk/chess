#include "Board.h"
#include "Square.h"

//creates an array pointer of each square in an 8x8 grid and puts it in _squares
Board::Board()
{
	for (int r = 0; r < DIMENSION; ++r)
	{
		for (int f = 0; f < DIMENSION; ++f)
		{
			_squares[r][f] = new Square(r, f);
		}
	}
}

//array must be deleted as a 'new' was created
Board::~Board()
{
	for (int r = 0; r < DIMENSION; ++r)
	{
		for (int f = 0; f < DIMENSION; ++f)
		{
			delete _squares[r][f];
		}
	}
}

//function to change the piece contained by a square
void
Board::setPiece(char file, int rank, Piece* piece)
{
	getSquare(file, rank)->setPiece(piece);
}

//pointer to what piece is contained by a square
Piece*
Board::getPiece(char file, int rank) const
{
	return getSquare(file, rank)->getPiece();
}

//bool returning whether or not a sqare contains a piece
bool
Board::hasPiece(char file, int rank) const
{
	return getSquare(file, rank)->hasPiece();
}

//returns a pointer to the square specified by the rank and file in the constructor
Square*
Board::getSquare(char file, int rank) const
{
	return _squares[getIndexByRank(rank)][getIndexByFile(file)];
}

int
Board::getIndexByFile(char file) const
{
	int index = file - 'a';
	if (index < 0)
	{
		index = 0;
	}
	if (index > 7)
	{
		index = 7;
	}
	return index;
}

int
Board::getIndexByRank(int rank) const
{
	int index = rank - 1;
	if (index < 0)
	{
		index = 0;
	}
	if (index > 7)
	{
		index = 7;
	}
	return index;
}
