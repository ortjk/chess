#include "Rook.h"

Rook::Rook(Kind kind, Color color) : Piece(kind, color)
{
}

Rook::~Rook()
{
} 

bool
Rook::canMove(Board* board, char fromFile, int fromRank, char toFile, int toRank) const 
{
	return false;
}
