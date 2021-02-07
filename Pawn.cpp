#include "Pawn.h"

Pawn::Pawn(Kind kind, Color color) : Piece(kind, color)
{
}

Pawn::~Pawn()
{
}

void Pawn::setHasMoved()
{
	hasMoved = true;
}

bool
Pawn::canMove(Board* board, Square toSquare) const 
{
	if (toSquare == this->getSquare() + 8 ||
		toSquare == this->getSquare() - 8 ||
		(toSquare == this->getSquare() + 16 && !hasMoved) ||
		(toSquare == this->getSquare() - 16 && !hasMoved))
	{
		return true;
	}
	return false;
}
