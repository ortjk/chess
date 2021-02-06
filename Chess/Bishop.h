#pragma once

#include "Piece.h"

class Board;

class Bishop : public Piece
{
public:
	Bishop(Kind kind, Color color);
	virtual ~Bishop();

	virtual bool canMove(Board* board, char fromFile, int fromRank, char toFile, int toRank) const; 
private:
};

