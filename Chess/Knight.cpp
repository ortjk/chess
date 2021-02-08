#include "Knight.h"

Knight::Knight(Kind kind, Color color) : Piece(kind, color)
{
}

Knight::~Knight()
{
} 

void Knight::setHasMoved()
{
}

bool
Knight::canMove(Board* board, Square toSquare) const 
{
	if (this->isSameColor(board, toSquare))
	{
		return false;
	}
	if (toSquare == this->getSquare() - 6  ||
		toSquare == this->getSquare() - 15 ||
		toSquare == this->getSquare() - 17 ||
		toSquare == this->getSquare() - 10 ||
		toSquare == this->getSquare() + 6  ||
		toSquare == this->getSquare() + 15 ||
		toSquare == this->getSquare() + 17 ||
		toSquare == this->getSquare() + 10)
	{
		return true;
	}
	return false;
}
