#include "Pawn.h"

Pawn::Pawn(Kind kind, Color color) : Piece(kind, color)
{
}

Pawn::~Pawn()
{
} 

bool
Pawn::canMove(Board* board, Board::Square toSquare) const 
{
	Board::Square fromSquare = this->getSquare();
	if (fromSquare == Board::NONE)
	{
		return false;
	}

	// TODO: check if this is the first move, if so we can move 2 spaces forward.

	return false;
}
