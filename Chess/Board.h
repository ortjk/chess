#pragma once
#include "Enums.h"
class Piece;

class Board
{
public:
	
	static int getFileIndex(Square square);
	static int getRankIndex(Square square); 
	static Square getSquareByIndices(int fileIndex, int rankIndex);

	Board();
	virtual ~Board();

	void setPiece(Square square, Piece* piece);
	Piece* getPiece(Square square) const;
	bool hasPiece(Square square) const;
	Piece* getFirstObstruction(Square fromSquare, Square toSquare, Direction direction);

private:
	const static int DIMENSION = 64;

	Piece* _squares[DIMENSION];
};

