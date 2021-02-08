#include "King.h"

King::King(Kind kind, Color color) : Piece(kind, color)
{

}

King::~King()
{

} 

void King::setHasMoved()
{
	hasMoved = true;
}

bool
King::canMove(Board* board, Square toSquare) const 
{
	if (this->isSameColor(board, toSquare))
	{
		return false;
	}
	if (toSquare == this->getSquare() - 7 ||
		toSquare == this->getSquare() - 8 ||
		toSquare == this->getSquare() - 9 ||
		toSquare == this->getSquare() - 1 ||
		toSquare == this->getSquare() + 7 ||
		toSquare == this->getSquare() + 8 ||
		toSquare == this->getSquare() + 9 ||
		toSquare == this->getSquare() + 1 ||
		toSquare == this->getSquare() + 2 && !hasMoved ||
		toSquare == this->getSquare() - 3 && !hasMoved)
	{
		return true;
	}


	return false;
}
