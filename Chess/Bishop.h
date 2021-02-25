#pragma once

#include "Piece.h"

class Board;

class Bishop : public Piece
{
public:
	Bishop(Kind kind, Color color);
	virtual ~Bishop();

	virtual void setHasMoved();
	virtual bool getHasMoved();

	virtual bool isFirstCapture(Board* board, Square square);

	virtual bool canMove(Board* board, Square toSquare) const; 
private:
};

