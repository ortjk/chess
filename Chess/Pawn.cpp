#include "Pawn.h"

Pawn::Pawn(Kind kind, Color color) : Piece(kind, color)
{
}

Pawn::~Pawn()
{
}

void Pawn::setHasMoved()
{
	hasMoved = true;
}

bool Pawn::getHasMoved()
{
	return false;
}

bool Pawn::isFirstCapture(Board* board, Square square)
{
	return Square();
}

bool
Pawn::canMove(Board* board, Square toSquare) const 
{
	if (this->isSameColor(board, toSquare))
	{
		return false;
	}

	//normal movement check
	if (toSquare == this->getSquare() + 8 &&
		!board->getPiece(toSquare) &&
		this->isBlack())
	{
		
		return true;

	}
	if (toSquare == this->getSquare() - 8 &&
		!board->getPiece(toSquare) &&
		this->isWhite())
	{
	
		return true;
	}

	//capture check
	if (toSquare == this->getSquare() + 7 ||
		toSquare == this->getSquare() + 9 ||
		toSquare == this->getSquare() - 7 ||
		toSquare == this->getSquare() - 9)
	{
		if (board->getPiece(toSquare))
		{
			if (board->getPiece(toSquare)->getColor() != this->getColor())
			{
				return true;
			}
		}
	}

	//double movement check
	if (toSquare == this->getSquare() + 16 && !hasMoved)
	{
		if (board->getFirstObstruction(this->getSquare(), toSquare, VERTICAL) == nullptr)
		{
			return true;
		}
	}
	if (toSquare == this->getSquare() - 16 && !hasMoved)
	{
		if (board->getFirstObstruction(this->getSquare(), toSquare, VERTICAL) == nullptr)
		{
			return true;
		}
	}

	return false;
}
