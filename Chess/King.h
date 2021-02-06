#pragma once

#include "Piece.h"

class Board;

class King : public Piece
{
public:
	King(Kind kind, Color color);
	virtual ~King();

	virtual bool canMove(Board* board, Board::Square toSquare) const; 
private:
};

