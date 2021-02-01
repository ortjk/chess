#pragma once
#include <iostream>
#include <vector>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>

class ChessPiece
{

public:
	enum PieceType
	{
		PAWN,
		BISHOP,
		KNIGHT,
		ROOK,
		QUEEN,
		KING
	};

	enum PieceColor
	{
		WHITE_PIECE = 0,
		BLACK_PIECE = 1
	};

	enum Direction
	{
		HORIZONTAL,
		VERTICAL,
		DIAGONAL,
		L_SHAPED
	};

	enum Distance
	{
		ONE = 1,
		NO_LIMIT = 0
	};

	struct Position
	{
		int letterPos;
		int numberPos;
	};


	void initVariables();

	ChessPiece(PieceType type, PieceColor color, int starting_letter, int starting_number);
	virtual ~ChessPiece();

	void setSpritePos(float xpos, float ypos);
	sf::Sprite getSprite();
	sf::IntRect getHitrect();
	Direction getPossibleDirection(int num_of_dirs);

private:
	Direction possibleDirection;
	Direction possibleDirection2;
	PieceColor pieceColor;
	Distance possibleDistance;

	sf::Texture piecesTexture;
	sf::Sprite sprite;

	sf::RectangleShape hitbox;

	Position piecePosition;
	
};

