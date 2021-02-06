#include "Board.h"
#include "Piece.h"

int
Board::getFileIndex(Square square)
{
    return square / 8;
}

int
Board::getRankIndex(Square square)
{
    return square % 8;
}

Board::Square
Board::getSquareByIndices(int fileIndex, int rankIndex)
{
    int index = fileIndex * 8 + rankIndex;
    if (A1 <= index && index <= H8)
    {
        return (Square) index;
    }
    return NONE;
}

//creates an array pointer of each square in an 8x8 grid and puts it in _squares
Board::Board()
{
	for (int i = 0; i < DIMENSION; ++i)
	{
		_squares[i] = 0;
	}
}

//array must be deleted as a 'new' was created
Board::~Board()
{
	for (int i = 0; i <= 64; ++i)
	{
		_squares[i] = 0;
	}
}

//function to change the piece contained by a square
void
Board::setPiece(Square square, Piece* piece)
{
	if (piece)
	{
		Square currentSquare = piece->getSquare();
		if (currentSquare != NONE)
		{
			// Remove the piece from where it was.
			_squares[currentSquare] = 0;	
		}

		piece->setSquare(square);
	}

	if (_squares[square])
	{
		// This is essentially a capture, for now just tell the piece currently occupying the square that it has no square.
		_squares[square]->setSquare(Board::NONE);
	}
	
	// Give the piece a new home.
	_squares[square] = piece;
}

//pointer to what piece is contained by a square
Piece*
Board::getPiece(Square square) const
{
	return _squares[square];
}

//bool returning whether or not a sqare contains a piece
bool
Board::hasPiece(Square square) const
{
	return _squares[square] != 0;
}
