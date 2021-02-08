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

bool
Bishop::canMove(Board* board, Square toSquare) const 
{
	if (this->isSameColor(board, toSquare))
	{
		return false;
	}
	for (int i = 1; i <= 8; i++)
	{
		if (toSquare == this->getSquare() - (7 * i) ||
			toSquare == this->getSquare() - (9 * i) || 
			toSquare == this->getSquare() + (7 * i) || 
			toSquare == this->getSquare() + (9 * i))
		{
			return true;
		}
	}
	return false;
}
