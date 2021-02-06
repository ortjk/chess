#include "Queen.h"

Queen::Queen(Kind kind, Color color) : Piece(kind, color)
{
}

Queen::~Queen()
{
} 

bool
Queen::canMove(Board* board, char fromFile, int fromRank, char toFile, int toRank) const 
{
	return false;
}
