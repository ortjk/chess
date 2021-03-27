#pragma once
#include "Enums.h"
#include <vector>

class Piece;

class Board
{
public:
	static const int DIMENSION = 64;
	
	static int getFileIndex(Square square);
	static int getRankIndex(Square square); 
	static Square getSquareByIndices(int fileIndex, int rankIndex);

	Board();
	virtual ~Board();

	void commit();
	const std::vector<Piece*>& getState(int moveNumber = TEMP) const;

	void setState(int moveNumber);

	void setPiece(Square square, Piece* piece);
	Piece* getPiece(Square square, int moveNumber = TEMP) const;
	bool hasPiece(Square square) const;
	Piece* getFirstObstruction(Square fromSquare, Square toSquare, Direction direction);

private:
	//there are two private variables: the _squares vector which is the current board state, and the _states vector which
	//holds all past states
	std::vector<Piece*> _squares;
	std::vector<std::vector<Piece*> > _states;
};

