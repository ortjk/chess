#pragma once

#include "Piece.h"

class Board;

class Knight : public Piece
{
public:
	Knight(Kind kind, Color color);
	virtual ~Knight();

	virtual bool canMove(Board* board, Board::Square toSquare) const; 
private:
};

