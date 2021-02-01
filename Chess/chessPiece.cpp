#include "chessPiece.h"

//loads the chess piece sprite sheet, sets the sprite's texture and scale
void ChessPiece::initVariables()
{
	if (!piecesTexture.loadFromFile("resources/Sprite-0003.png")) {
		std::cout << "ERROR COULD NOT LOAD PIECES TEXTURE\n";
	}

	sprite.setTexture(piecesTexture);
	sprite.setScale(sf::Vector2f(8.f, 8.f));
	
}

//constructor for chess pieces. accepts the piece type, color, and the starting position, then sets values accordingly
//also assigns the correct texture depending on the type, and makes a hitbox for mouse to click
//the piece type is the most important parameter, it dictates how many possible directions it can have and the possible distance
ChessPiece::ChessPiece(PieceType type, PieceColor color, int starting_letter, int starting_number)
{
	initVariables();
	switch (type)
	{
	case ChessPiece::PAWN:
		possibleDirection = DIAGONAL;
		possibleDistance = ONE;
		sprite.setTextureRect(sf::IntRect(81, color * 16, 16, 15));
		break;

	case ChessPiece::BISHOP:
		possibleDirection = DIAGONAL;
		possibleDistance = NO_LIMIT;

		sprite.setTextureRect(sf::IntRect(33, color * 16, 16, 15));
		break;

	case ChessPiece::KNIGHT:
		possibleDirection = L_SHAPED;
		possibleDistance = NO_LIMIT;

		sprite.setTextureRect(sf::IntRect(17, color * 16, 16, 15));
		break;

	case ChessPiece::ROOK:
		possibleDirection = HORIZONTAL;
		possibleDistance = NO_LIMIT;

		sprite.setTextureRect(sf::IntRect(0, color * 16, 16, 15));
		break;

	case ChessPiece::QUEEN:
		possibleDirection = DIAGONAL;
		possibleDirection = HORIZONTAL;
		possibleDistance = NO_LIMIT;

		sprite.setTextureRect(sf::IntRect(49, color * 16, 16, 15));
		break;

	case ChessPiece::KING:
		possibleDirection = DIAGONAL;
		possibleDirection = HORIZONTAL;
		possibleDistance = ONE;

		sprite.setTextureRect(sf::IntRect(65, color * 16, 16, 15));
		break;

	default:
		std::cout << "UNKNOWN PIECE COLOR\n";
		break;
	}
	pieceColor = color;
	piecePosition.letterPos = starting_letter;
	piecePosition.numberPos = starting_number;

	hitbox.setSize(sf::Vector2f(16.f, 16.f));
	hitbox.setFillColor(sf::Color::Transparent);
	hitbox.setScale(sprite.getScale());
}

ChessPiece::~ChessPiece()
{

}

//allows the sprite to be set by the mouse when it is clicked
void ChessPiece::setSpritePos(float xpos, float ypos)
{
	sprite.setPosition(sf::Vector2f(xpos - 16.f * 4.f, ypos - 16.f * 4.f));
}

sf::Sprite ChessPiece::getSprite()
{
	return sprite;
}

//the hitbox must be returned as an intrect, not a rectangleshape because of the mousepos properties
sf::IntRect ChessPiece::getHitrect()
{
	sf::IntRect hitRect(sprite.getPosition().x, sprite.getPosition().y, 128, 128);
	return hitRect;
}

ChessPiece::Direction ChessPiece::getPossibleDirection(int num_of_dirs)
{
	return possibleDirection;
}
