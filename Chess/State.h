#pragma once
#include "Board.h"
#include "Piece.h"
#include <SFML/Graphics.hpp>

class Board;
class SpriteFactory;

class State
{
public:
	State();
	virtual ~State();
	
	void startMove(Board::Square square);
	void endMove(Board::Square square);
	
	void reset();

	const sf::Sprite& getSprite(Piece::Color, Piece::Kind) const;

private:
	Board* _board;
	Piece* _pieces[Piece::COLOR_COUNT][Piece::KIND_COUNT];
	SpriteFactory* _spriteFactory;
};
