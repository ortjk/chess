#pragma once
#include "Piece.h"
#include<SFML/Graphics.hpp>
#include <map>

class SpriteFactory
{
public:
    SpriteFactory();
    virtual ~SpriteFactory();

    const sf::Sprite& getSprite(Piece* piece);

private:
    const sf::Sprite& createSprite(Piece* piece);

    int getKindIndex(Piece::Kind kind) const;
    int getColorIndex(Piece::Color kind) const;

    std::map<Piece*, sf::Sprite> _spriteMap;
};