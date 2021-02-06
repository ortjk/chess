#pragma once

#include "Piece.h"

class Board;

class Rook : public Piece
{
public:
	Rook(Kind kind, Color color);
	virtual ~Rook();

	virtual bool canMove(Board* board, char fromFile, int fromRank, char toFile, int toRank) const; 
private:
};

