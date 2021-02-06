#include "King.h"

King::King(Kind kind, Color color) : Piece(kind, color)
{

}

King::~King()
{

} 

bool
King::canMove(Board* board, Board::Square toSquare) const 
{
	return false;
}
