#pragma once

#include "Piece.h"

class Board;

class Pawn : public Piece
{
public:
	Pawn(Kind kind, Color color);
	virtual ~Pawn();

	virtual void setHasMoved();
	virtual bool getHasMoved();

	virtual bool isFirstCapture(Board* board, Square square);

	virtual bool canMove(Board* board, Square toSquare) const; 
private:
	bool hasMoved = false;
};

