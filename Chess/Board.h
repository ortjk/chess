#pragma once

#include "Square.h"

class Board
{
public:
	Board();
	virtual ~Board();

	void setPiece(char file, int rank, Piece* piece);
	Piece* getPiece(char file, int rank) const;
	bool hasPiece(char file, int rank) const;


private:
	Square* getSquare(char file, int rank) const;
	int getIndexByFile(char file) const;
	int getIndexByRank(int rank) const;

private:
	const static int DIMENSION = 8;

	Square* _squares[DIMENSION][DIMENSION];
};

