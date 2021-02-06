#include "Knight.h"

Knight::Knight(Kind kind, Color color) : Piece(kind, color)
{
}

Knight::~Knight()
{
} 

bool
Knight::canMove(Board* board, Board::Square toSquare) const 
{
	return false;
}
