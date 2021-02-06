#include "Rook.h"

Rook::Rook(Kind kind, Color color) : Piece(kind, color)
{
}

Rook::~Rook()
{
} 

bool
Rook::canMove(Board* board, Board::Square toSquare) const 
{
	return false;
}
