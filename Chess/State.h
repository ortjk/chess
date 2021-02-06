#pragma once

#include "Piece.h"

class Board;

class State
{
public:
	State();
	virtual ~State();
	
	void startMove(char file, int rank);
	void endMove(char file, int rank);
	
	void reset();

	sf::Sprite getSprite(int p, int c);
private:
	Board* _board;
	Piece* _pieces[Piece::COLOR_COUNT][Piece::KIND_COUNT];
};
