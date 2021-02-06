#pragma once

#include "Piece.h"

class Board;

class Bishop : public Piece
{
public:
	Bishop(Kind kind, Color color);
	virtual ~Bishop();

	virtual bool canMove(Board* board, Board::Square toSquare) const; 
private:
};

