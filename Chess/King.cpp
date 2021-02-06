#include "King.h"

King::King(Kind kind, Color color) : Piece(kind, color)
{

}

King::~King()
{

} 

bool
King::canMove(Board* board, char fromFile, int fromRank, char toFile, int toRank) const 
{
	return false;
}
