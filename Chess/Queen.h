#pragma once

#include "Piece.h"

class Board;

class Queen : public Piece
{
public:
	Queen(Kind kind, Color color);
	virtual ~Queen();

	virtual bool canMove(Board* board, char fromFile, int fromRank, char toFile, int toRank) const; 
private:
};

