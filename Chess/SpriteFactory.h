#pragma once
#include "Piece.h"
#include<SFML/Graphics.hpp>
#include <map>

class SpriteFactory
{
public:
    SpriteFactory();
    virtual ~SpriteFactory();

    sf::Sprite& getSprite(Piece* piece);
	void updatePosition(Piece* piece, Square square);

private:
	sf::Texture texture;

    sf::Sprite& createSprite(Piece* piece);

    int getKindIndex(Kind kind) const;
    int getColorIndex(Color kind) const;

	/*
	the call below creates a map. 
	a map is a code and return type function, where you call the map with one of the values input and it will return the other value input
	---e.g.---
	map<string, float> m;
	m["code"] = 15;
	return m["code"];
	---^this will return 15^---
	*/
    std::map<Piece*, sf::Sprite> _spriteMap;
};