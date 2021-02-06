#include "Queen.h"

Queen::Queen(Kind kind, Color color) : Piece(kind, color)
{
}

Queen::~Queen()
{
} 

bool
Queen::canMove(Board* board, Board::Square toSquare) const 
{
	return false;
}
