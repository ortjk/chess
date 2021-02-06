#include "Pawn.h"

Pawn::Pawn(Kind kind, Color color) : Piece(kind, color)
{
}

Pawn::~Pawn()
{
} 

bool
Pawn::canMove(Board* board, char fromFile, int fromRank, char toFile, int toRank) const 
{
	Square* square = getSquare();
	if (!square)
	{
		return false;
	}

	// TODO: check if this is the first move, if so we can move 2 spaces forward.

	return false;
}
