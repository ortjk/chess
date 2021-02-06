#pragma once

#include "Piece.h"

class Board;

class King : public Piece
{
public:
	King(Kind kind, Color color);
	virtual ~King();

	virtual bool canMove(Board* board, char fromFile, int fromRank, char toFile, int toRank) const; 
private:
};

