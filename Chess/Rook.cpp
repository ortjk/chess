#include "Rook.h"

Rook::Rook(Kind kind, Color color) : Piece(kind, color)
{
}

Rook::~Rook()
{
} 

void Rook::setHasMoved()
{
}

bool
Rook::canMove(Board* board, Square toSquare) const 
{
	for (int i = 1; i <= 8; i++)
	{
		if (toSquare == this->getSquare() + (1 * i) ||
			toSquare == this->getSquare() - (8 * i) ||
			toSquare == this->getSquare() - (1 * i) ||
			toSquare == this->getSquare() + (8 * i))
		{
			return true;
		}
	}
	return false;
}
