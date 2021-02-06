#pragma once
#include "Board.h"

class Piece
{
public:
	enum Kind
	{
		A_PAWN,
		B_PAWN,
		C_PAWN,
		D_PAWN,
		E_PAWN,
		F_PAWN,
		G_PAWN,
		H_PAWN,
		Q_ROOK,
		Q_KNIGHT, 
		Q_BISHOP, 
		QUEEN, 
		KING, 
		K_BISHOP,
		K_KNIGHT,
		K_ROOK,
		KIND_COUNT
	};

	enum Color
	{
		WHITE,
		BLACK,
		COLOR_COUNT
	};

	Piece(Kind kind, Color color);
	virtual ~Piece();

	Kind getKind() const;
	Color getColor() const;

	void setSquare(Board::Square square);
	Board::Square getSquare() const;

	bool isBlack() const;
	bool isWhite() const;
	bool isPawn() const;
	bool isRook() const;
	bool isKnight() const;
	bool isBishop() const;
	bool isQueen() const;
	bool isKing() const;

	virtual bool canMove(Board* board, Board::Square toSquare) const = 0;

private:
	int _kindnum;

	const Kind _kind; 
	const Color _color; 

	Board::Square _square;
};
