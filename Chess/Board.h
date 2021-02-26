#pragma once
#include "Enums.h"
#include <vector>

class Piece;

class Board
{
public:
	static const int DIMENSION = 64;
	static const int TEMP = -2;
	static const int LAST = -1;
	
	static int getFileIndex(Square square);
	static int getRankIndex(Square square); 
	static Square getSquareByIndices(int fileIndex, int rankIndex);

	Board();
	virtual ~Board();

	void commit();
	const std::vector<Piece*>& getState(int moveNumber = LAST) const;

	void setPiece(Square square, Piece* piece);
	Piece* getPiece(Square square, int moveNumber = LAST) const;
	bool hasPiece(Square square) const;
	Piece* getFirstObstruction(Square fromSquare, Square toSquare, Direction direction);

private:

	std::vector<Piece*> _squares;
	std::vector<std::vector<Piece*> > _states;
};

