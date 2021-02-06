#pragma once

#include "Piece.h"

class Board;

class Pawn : public Piece
{
public:
	Pawn(Kind kind, Color color);
	virtual ~Pawn();

	virtual bool canMove(Board* board, Board::Square toSquare) const; 
private:
};

