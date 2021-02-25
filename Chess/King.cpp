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

bool King::getHasMoved()
{
	return false;
}

bool King::isFirstCapture(Board * board, Square square)
{
	return Square();
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
		toSquare == this->getSquare() + 1)
	{
		return true;
	}

	if (toSquare == this->getSquare() + 2 && !hasMoved && !board->getPiece(Square(toSquare + 1))->getHasMoved())
	{
		if (board->getFirstObstruction(this->getSquare(), toSquare, HORIZONTAL) == nullptr)
		{
			board->setPiece(Square(toSquare - 1), board->getPiece(Square(toSquare + 1)));
			return true;
		}
	}
	if (toSquare == this->getSquare() - 3 && !hasMoved && !board->getPiece(Square(toSquare - 1))->getHasMoved())
	{
		if (board->getFirstObstruction(this->getSquare(), toSquare, HORIZONTAL) == nullptr)
		{
			board->setPiece(Square(toSquare + 1), board->getPiece(Square(toSquare - 1)));
			return true;
		}
	}
	return false;
}
