#include "Bishop.h"

Bishop::Bishop(Kind kind, Color color) : Piece(kind, color)
{
}

Bishop::~Bishop()
{
} 

void Bishop::setHasMoved()
{
}

bool Bishop::getHasMoved()
{
	return false;
}

bool Bishop::isFirstCapture(Board * board, Square square)
{
	return Square();
}

bool
Bishop::canMove(Board* board, Square toSquare) const 
{
	if (this->isSameColor(board, toSquare))
	{
		return false;
	}
	for (int i = 1; i <= 8; i++)
	{
		if (toSquare == this->getSquare() - (7 * i))
		{
			if (board->getFirstObstruction(this->getSquare(), toSquare, POSITIVE_DIAGONAL) == nullptr)
			{
				return true;
			}
		}
		else if (toSquare == this->getSquare() - (9 * i))
		{
			if (board->getFirstObstruction(this->getSquare(), toSquare, NEGATIVE_DIAGONAL) == nullptr)
			{
				return true;
			}
		}
		else if (toSquare == this->getSquare() + (7 * i))
		{
			if (board->getFirstObstruction(this->getSquare(), toSquare, POSITIVE_DIAGONAL) == nullptr)
			{
				return true;
			}
		}
		else if (toSquare == this->getSquare() + (9 * i))
		{
			if (board->getFirstObstruction(this->getSquare(), toSquare, NEGATIVE_DIAGONAL) == nullptr)
			{
				return true;
			}
		}
	}
	return false;
}
