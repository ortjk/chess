#include "Piece.h"

//a piece can be created with a kind, color, and its square set to none
Piece::Piece(Kind kind, Color color)
	: _kind(kind), _color(color), _square(NONE)
{
}

Piece::~Piece()
{
}

//returns invalid if space that the move was started on was empty
Kind
Piece::getKind() const
{
	return _kind;
}

Color
Piece::getColor() const
{
	return _color;
}

//sets the square that the piece should occupy
void
Piece::setSquare(Square square)
{
	_square = square;
}

//gets a pointer to the square that the piece is occupying
Square
Piece::getSquare() const
{
	return _square;
}

//returns true if color is black
bool
Piece::isBlack() const
{
	return _color == BLACK;
}

//returns true if color is white
bool
Piece::isWhite() const
{
	return _color == WHITE;
}

//returns true if the piece is any kind of pawn
bool
Piece::isPawn() const
{
	switch (_kind)
	{
	case A_PAWN:
	case B_PAWN:
	case C_PAWN:
	case D_PAWN:
	case E_PAWN:
	case F_PAWN:
	case G_PAWN:
	case H_PAWN:
		return true;
	default:
		break;
	}
	return false;
}

//returns true if the piece is a rook
bool
Piece::isRook() const
{
	switch (_kind)
	{
	case Q_ROOK:
	case K_ROOK:
		return true;
	default:
		break;
	}
	return false;
}

//returns true if the piece is a knight
bool
Piece::isKnight() const
{
	switch (_kind)
	{
	case Q_KNIGHT:
	case K_KNIGHT:
		return true;
	default:
		break;
	}
	return false;
}

//returns true if the piece is a bishop
bool
Piece::isBishop() const
{
	switch (_kind)
	{
	case Q_BISHOP:
	case K_BISHOP:
		return true;
	default:
		break;
	}
	return false;
}

//returns true if the piece is a queen
bool
Piece::isQueen() const
{
	return _kind == QUEEN;
}

//returns true if the piece is a king
bool
Piece::isKing() const
{
	return _kind == KING;
}

bool Piece::isSameColor(Board* board, Square toSquare) const
{
	if (board->getPiece(toSquare))
	{
		if (this->_color == board->getPiece(toSquare)->getColor())
		{
			return true;
		}
	}
	return false;
}

