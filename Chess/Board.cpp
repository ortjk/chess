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

Square
Board::getSquareByIndices(int fileIndex, int rankIndex)
{
	//returns the square enum at the input rank and file by using math
    int index = fileIndex * 8 + rankIndex;
    if (A8 <= index && index <= H1)
    {
        return (Square) index;
    }
    return NONE;
}

//creates 64 pices on info that store whether or not a piece is there
Board::Board()
	: _squares(DIMENSION, 0)
{
}

//clears every space
Board::~Board()
{
}

void
Board::commit()
{
	_states.push_back(_squares);
}

const std::vector<Piece*>&
Board::getState(int moveNumber) const
{
	switch (moveNumber)
	{
		case TEMP:
			return _squares;
		case LAST:
			return _states[_states.size() - 1];
		default:
			break;
	}
	return _states[moveNumber];
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
		_squares[square]->setSquare(NONE);
	}
	
	// Give the piece a new home.
	_squares[square] = piece;
}

//pointer to what piece is contained by a square
Piece*
Board::getPiece(Square square, int moveNumber) const
{
	return getState(moveNumber)[square];
}

//bool returning whether or not a sqare contains a piece
bool
Board::hasPiece(Square square) const
{
	return this->getPiece(square, 0) != 0;
}

//returns first piece inbetween point a and point b
Piece*
Board::getFirstObstruction(Square fromSquare, Square toSquare, Direction direction)
{
	if (direction == VERTICAL)
	{
		if (fromSquare < toSquare)
		{
			for (int i = 1; i <= 7; i++)
			{
				if (Square(fromSquare + (i * 8)) == toSquare)
				{
					return nullptr;
				}

				if (_squares[fromSquare + (i * 8)] != 0)
				{
					return _squares[fromSquare + (i * 8)];
				}
			}
			return nullptr;
		}
		for (int i = -1; i >= -7; i--)
		{
			if (Square(fromSquare + (i * 8)) == toSquare)
			{
				return nullptr;
			}

			if (_squares[fromSquare + (i * 8)] != 0)
			{
				return _squares[fromSquare + (i * 8)];
			}
		}
	}
	
	if (direction == HORIZONTAL)
	{
		if (fromSquare < toSquare)
		{
			for (int i = 1; i <= 7; i++)
			{
				if (Square(fromSquare + i) == toSquare)
				{
					return nullptr;
				}
				if (_squares[fromSquare + i] != 0)
				{
					return _squares[fromSquare + i];
				}
			}
			return nullptr;
		}

	for (int i = -1; i >= -7; i--)
	{
		if (Square(fromSquare + i) == toSquare)
		{
			return nullptr;
		}
		if (_squares[fromSquare + i] != 0)
		{
			return _squares[fromSquare + i];
		}
		}
	}

	//if diagonal
	if (direction == POSITIVE_DIAGONAL)
	{
		if (fromSquare < toSquare)
		{
			for (int i = 1; i <= 7; i++)
			{
				if (Square(fromSquare + (i * 7)) == toSquare)
				{
					return nullptr;
				}

				if (_squares[fromSquare + (i * 7)] != 0)
				{
					return _squares[fromSquare + (i * 7)];
				}
			}
			return nullptr;
		}
		for (int i = -1; i >= -7; i--)
		{
			if (Square(fromSquare + (i * 7)) == toSquare)
			{
				return nullptr;
			}

			if (_squares[fromSquare + (i * 7)] != 0)
			{
				return _squares[fromSquare + (i * 7)];
			}
		}
	}
	if (direction == NEGATIVE_DIAGONAL)
	{
		if (fromSquare < toSquare)
		{
			for (int i = 1; i <= 7; i++)
			{
				if (Square(fromSquare + (i * 9)) == toSquare)
				{
					return nullptr;
				}

				if (_squares[fromSquare + (i * 9)] != 0)
				{
					return _squares[fromSquare + (i * 9)];
				}
			}
			return nullptr;
		}
		for (int i = -1; i >= -9; i--)
		{
			if (Square(fromSquare + (i * 9)) == toSquare)
			{
				return nullptr;
			}

			if (_squares[fromSquare + (i * 9)] != 0)
			{
				return _squares[fromSquare + (i * 9)];
			}
		}
	}

	return nullptr;
}
