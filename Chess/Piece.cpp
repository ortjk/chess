#include "Piece.h"
#include "Square.h"



void Piece::initVariables()
{
	//switch to reorder the piece type into a form usable by the sprite sheet. writes new position to variable _kindnum
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
		_kindnum = 5;
		break;
	case Q_ROOK:
	case K_ROOK:
		_kindnum = 0;
		break;
	case Q_KNIGHT:
	case K_KNIGHT:
		_kindnum = 1;
		break;
	case Q_BISHOP:
	case K_BISHOP:
		_kindnum = 2;
		break;
	case QUEEN:
		_kindnum = 3;
		break;
	case KING:
		_kindnum = 4;
		break;
	default:
		_kindnum = 0;
		break;
	}


	if (!_texture.loadFromFile("resources/Sprite-0003.png")) 
	{
		std::cout << "ERROR COULD NOT LOAD BOARD TEXTURE\n";
	}

	_sprite.setTexture(_texture);

	_sprite.setTextureRect(sf::IntRect((16 * _kindnum), (16 * _color), 16, 16));

	_sprite.setScale(8.f, 8.f);
}

//a piece can be created with a kind, color, and its square set to 0
Piece::Piece(Kind kind, Color color)
	: _kind(kind), _color(color), _square(0)
{
	initVariables();
}

Piece::~Piece()
{
}

//sets the square that the piece should occupy
void
Piece::setSquare(Square* square)
{
	_square = square;
}

//gets a pointer to the square that the piece is occupying
Square*
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

sf::Sprite Piece::getSprite()
{
	int numFile;
	int numRank;

	switch (this->_square->getFile())
	{
	case 'a':
		numFile = 0;
	case 'b':
		numFile = 1;
	case 'c':
		numFile = 2;
	case 'd':
		numFile = 3;
	case 'e':
		numFile = 4;
	case 'f':
		numFile = 5;
	case 'g':
		numFile = 6;
	case 'h':
		numFile = 7;
	default:
		numFile = 0;
	}

	numRank = (this->_square->getRank() - 1);

	_sprite.setPosition(sf::Vector2f(10.f + (10 * numFile), 10.f + (10 * numRank)));
	return _sprite;
}

