#include "Bishop.h"

Bishop::Bishop(Kind kind, Color color) : Piece(kind, color)
{
}

Bishop::~Bishop()
{
} 

bool
Bishop::canMove(Board* board, char fromFile, int fromRank, char toFile, int toRank) const 
{
	return false;
}
