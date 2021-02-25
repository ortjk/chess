#pragma once

#include "Piece.h"

class Board;

class Rook : public Piece
{
public:
	Rook(Kind kind, Color color);
	virtual ~Rook();

	virtual void setHasMoved();
	virtual bool getHasMoved();

	virtual bool isFirstCapture(Board* board, Square square);

	virtual bool canMove(Board* board, Square toSquare) const; 
private:
	bool hasMoved = false;
};

