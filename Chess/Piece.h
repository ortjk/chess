#pragma once
#include <iostream>
#include <vector>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>

class Board;
class Square;

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

	void initVariables();

	Piece(Kind kind, Color color);
	virtual ~Piece();

	void setSquare(Square* square);
	Square* getSquare() const;

	bool isBlack() const;
	bool isWhite() const;
	bool isPawn() const;
	bool isRook() const;
	bool isKnight() const;
	bool isBishop() const;
	bool isQueen() const;
	bool isKing() const;

	virtual 
	bool canMove(Board* board, char fromFile, int fromRank, char toFile, int toRank) const = 0;

	sf::Sprite getSprite();
private:
	int _kindnum;

	sf::Texture _texture;
	sf::Sprite _sprite;

	const Kind _kind; 
	const Color _color; 

	Square* _square;
};
