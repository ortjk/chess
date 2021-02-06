#pragma once

#include "Piece.h"

class Board;

class Pawn : public Piece
{
public:
	Pawn(Kind kind, Color color);
	virtual ~Pawn();

	virtual bool canMove(Board* board, char fromFile, int fromRank, char toFile, int toRank) const; 
private:
};

