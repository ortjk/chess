#include "Square.h"
#include "Piece.h"

//creates a square with a rank and file
Square::Square(char file, int rank)
	: _file(file), _rank(rank), _piece(0)
{
}

Square::~Square()
{
}

//sets the piece contained by the square to the piece input by the constructor
void
Square::setPiece(Piece* piece)
{
	_piece = piece;
	_piece->setSquare(this);
}

//returns the piece occupying the square
Piece*
Square::getPiece() const
{
	return _piece;
}

//returns true if the piece contained by the square exists
bool
Square::hasPiece() const
{
	return _piece != 0;
}

char Square::getFile() const
{
	return _file;
}

int Square::getRank() const
{
	return _rank;
}

