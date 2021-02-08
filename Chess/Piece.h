#pragma once
#include "Board.h"

class Piece
{
public:
	
	Piece(Kind kind, Color color);
	virtual ~Piece();

	Kind getKind() const;
	Color getColor() const;

	void setSquare(Square square);
	Square getSquare() const;

	bool isBlack() const;
	bool isWhite() const;
	bool isPawn() const;
	bool isRook() const;
	bool isKnight() const;
	bool isBishop() const;
	bool isQueen() const;
	bool isKing() const;

	bool isSameColor(Board* board, Square toSquare) const;

	virtual void setHasMoved() = 0;

	virtual bool canMove(Board* board, Square toSquare) const = 0;

private:
	int _kindnum;

	const Kind _kind; 
	const Color _color; 

	Square _square;
};
