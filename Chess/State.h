#pragma once
#include "Hitbox.h"


class Board;
class SpriteFactory;
class Hitbox;

class State
{
public:
	State();
	virtual ~State();
	
	void startMove(Square square);
	void endMove(Square square);
	
	void squareClicked(sf::Vector2i point);
	void squareReleased(sf::Vector2i point);

	void reset();

	const sf::Sprite& getSprite(Color, Kind) const;

private:
	Board* _board;
	Piece* _pieces[COLOR_COUNT][KIND_COUNT];
	SpriteFactory* _spriteFactory;
	Piece* _pickedPiece;
	Hitbox _hitbox;
};
