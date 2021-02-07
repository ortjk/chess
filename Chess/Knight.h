#pragma once

#include "Piece.h"

class Board;

class Knight : public Piece
{
public:
	Knight(Kind kind, Color color);
	virtual ~Knight();

	virtual void setHasMoved();
	virtual bool canMove(Board* board, Square toSquare) const; 
private:
};

