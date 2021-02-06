#include "Knight.h"

Knight::Knight(Kind kind, Color color) : Piece(kind, color)
{
}

Knight::~Knight()
{
} 

bool
Knight::canMove(Board* board, char fromFile, int fromRank, char toFile, int toRank) const 
{
	return false;
}
