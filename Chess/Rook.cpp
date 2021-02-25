#include "Rook.h"

Rook::Rook(Kind kind, Color color) : Piece(kind, color)
{
}

Rook::~Rook()
{
} 

void Rook::setHasMoved()
{
	this->hasMoved = true;
}

bool Rook::getHasMoved()
{
	return this->hasMoved;
}

bool Rook::isFirstCapture(Board* board, Square square)
{
	return Square();
}

bool
Rook::canMove(Board* board, Square toSquare) const 
{
	if (this->isSameColor(board, toSquare))
	{
		return false;
	}
	
	//preventing weird movement bug
	if (toSquare == this->getSquare() - 7 ||
		toSquare == this->getSquare() - 6 ||
		toSquare == this->getSquare() + 7 ||
		toSquare == this->getSquare() + 6)
	{
		return false;
	}
	
	//normal movement check
	for (int i = 1; i <= 7; i++)
	{
		if (toSquare == this->getSquare() + (1 * i))
		{
			if (board->getFirstObstruction(this->getSquare(), toSquare, HORIZONTAL) == nullptr)
			{
				return true;
			}
		}
		else if (toSquare == this->getSquare() - (8 * i))
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
		else if (toSquare == this->getSquare() + (8 * i))
		{
			if (board->getFirstObstruction(this->getSquare(), toSquare, VERTICAL) == nullptr)
			{
				return true;
			}
		}
	}
	return false;
}
