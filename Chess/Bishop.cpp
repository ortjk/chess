#include "Bishop.h"

Bishop::Bishop(Kind kind, Color color) : Piece(kind, color)
{
}

Bishop::~Bishop()
{
} 

bool
Bishop::canMove(Board* board, Board::Square toSquare) const 
{
	return false;
}
