#include "SpriteFactory.h"
#include <iostream>

SpriteFactory::SpriteFactory()
{

}

SpriteFactory::~SpriteFactory()
{

}

const sf::Sprite&
SpriteFactory::getSprite(Piece* piece) 
{
    std::map<Piece*, sf::Sprite>::const_iterator p = _spriteMap.find(piece);
    if (p != _spriteMap.end())
    {
        return p->second;
    }

    return createSprite(piece);
}

const sf::Sprite&
SpriteFactory::createSprite(Piece* piece)
{
    sf::Texture texture;
    if (!texture.loadFromFile("resources/Sprite-0003.png")) 
	{
		std::cout << "ERROR COULD NOT LOAD BOARD TEXTURE\n";
	}

    int kindIndex = this->getKindIndex(piece->getKind());
    int colorIndex = this->getColorIndex(piece->getColor());

    sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect((16 * kindIndex), (16 * colorIndex), 16, 16));
	sprite.setScale(8.f, 8.f);
    _spriteMap[piece] = sprite;

    return _spriteMap[piece];
}

int
SpriteFactory::getKindIndex(Piece::Kind kind) const
{
    switch (kind)
	{
	case Piece::A_PAWN:
	case Piece::B_PAWN:
	case Piece::C_PAWN:
	case Piece::D_PAWN:
	case Piece::E_PAWN:
	case Piece::F_PAWN:
	case Piece::G_PAWN:
	case Piece::H_PAWN:
		return 5;
	case Piece::Q_ROOK:
	case Piece::K_ROOK:
		return 0;
	case Piece::Q_KNIGHT:
	case Piece::K_KNIGHT:
		return 1;
	case Piece::Q_BISHOP:
	case Piece::K_BISHOP:
		return 2;
	case Piece::QUEEN:
		return 3;
	case Piece::KING:
		return 4;
	default:
        break;
	}
    return 0;
}

int
SpriteFactory::getColorIndex(Piece::Color color) const
{
    switch (color)
    {
    case Piece::BLACK:
        return 0;
    case Piece::WHITE:
        return 1;
    default:
        break;
    }
    return 0;
}