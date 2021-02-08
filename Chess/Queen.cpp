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

bool
Queen::canMove(Board* board, Square toSquare) const 
{
	if (this->isSameColor(board, toSquare))
	{
		return false;
	}
	for (int i = 1; i <= 8; i++)
	{
		if (toSquare == this->getSquare() - (7 * i) ||
			toSquare == this->getSquare() - (8 * i) ||
			toSquare == this->getSquare() - (1 * i) ||
			toSquare == this->getSquare() + (1 * i) ||
			toSquare == this->getSquare() + (8 * i) ||
			toSquare == this->getSquare() - (9 * i) ||
			toSquare == this->getSquare() + (7 * i) ||
			toSquare == this->getSquare() + (9 * i))
		{
			return true;
		}
	}
	return false;
}
