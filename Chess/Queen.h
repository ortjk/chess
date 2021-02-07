#pragma once

#include "Piece.h"

class Board;

class Queen : public Piece
{
public:
	Queen(Kind kind, Color color);
	virtual ~Queen();

	virtual void setHasMoved();
	virtual bool canMove(Board* board, Square toSquare) const; 
private:
};

