#pragma once

#include "Piece.h"

class Board;

class King : public Piece
{
public:
	King(Kind kind, Color color);
	virtual ~King();

	virtual void setHasMoved();
	virtual bool canMove(Board* board, Square toSquare) const; 
private:
	bool hasMoved = false;
};

