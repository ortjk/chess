#pragma once
enum Square
{
	NONE = -1,
	A8, B8, C8, D8, E8, F8, G8, H8,
	A7, B7, C7, D7, E7, F7, G7, H7,
	A6, B6, C6, D6, E6, F6, G6, H6,
	A5, B5, C5, D5, E5, F5, G5, H5,
	A4, B4, C4, D4, E4, F4, G4, H4,
	A3, B3, C3, D3, E3, F3, G3, H3,
	A2, B2, C2, D2, E2, F2, G2, H2,
	A1, B1, C1, D1, E1, F1, G1, H1
};

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
	A_X_QUEEN,
	B_X_QUEEN,
	C_X_QUEEN,
	D_X_QUEEN,
	E_X_QUEEN,
	F_X_QUEEN,
	G_X_QUEEN,
	H_X_QUEEN,
	KIND_COUNT
};

enum Color
{
	WHITE,
	BLACK,
	COLOR_COUNT
};

enum Direction
{
	VERTICAL,
	HORIZONTAL,
	POSITIVE_DIAGONAL,
	NEGATIVE_DIAGONAL
};

enum StateNames
{
	TEMP = -2,
	LAST = -1
};