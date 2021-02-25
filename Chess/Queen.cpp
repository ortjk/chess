#include "Queen.h"

Queen::Queen(Kind kind, Color color) : Piece(kind, color)
{
}

Queen::~Queen()
{
} 

void Queen::setHasMoved()
{
}

bool Queen::getHasMoved()
{
	return false;
}

bool Queen::isFirstCapture(Board * board, Square square)
{
	return Square();
}

bool
Queen::canMove(Board* board, Square toSquare) const 
{
	if (this->isSameColor(board, toSquare))
	{
		return false;
	}
	for (int i = 1; i <= 8; i++)
	{
		if (toSquare == this->getSquare() - (8 * i))
		{
			if (board->getFirstObstruction(this->getSquare(), toSquare, VERTICAL) == nullptr)
			{
				return true;
			}
		}
		else if (toSquare == this->getSquare() - (1 * i))
		{
			if (board->getFirstObstruction(this->getSquare(), toSquare, HORIZONTAL) == nullptr)
			{
				return true;
			}
		}
		else if (toSquare == this->getSquare() + (1 * i))
		{
			if (board->getFirstObstruction(this->getSquare(), toSquare, HORIZONTAL) == nullptr)
			{
				return true;
			}
		}
		else if (toSquare == this->getSquare() + (8 * i))
		{
			if (board->getFirstObstruction(this->getSquare(), toSquare, VERTICAL) == nullptr)
			{
				return true;
			}
		}
		else if (toSquare == this->getSquare() - (7 * i))
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
