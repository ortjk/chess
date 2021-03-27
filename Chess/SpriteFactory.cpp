#include "SpriteFactory.h"
#include <iostream>

SpriteFactory::SpriteFactory()
{
	if (!texture.loadFromFile("resources/Sprite-0003.png"))
	{
		std::cout << "ERROR COULD NOT LOAD SPRITE SHEET\n";
	}
}

SpriteFactory::~SpriteFactory()
{

}

sf::Sprite&
SpriteFactory::getSprite(Piece* piece) 
{
	//the map call below is a more complex call of the map. it uses an iterator.
	//the for loop will replay until it finds the sprite of the input sprite
    std::map<Piece*, sf::Sprite>::iterator p = _spriteMap.find(piece);
    if (p != _spriteMap.end())
    {
		//returns the second value of the map at the adress p
        return p->second;
    }

	//if the a sprite for the input piece cannot be found, a new one will be created and returned
    return createSprite(piece);
}

void SpriteFactory::updatePosition(Piece* piece, Square square)
{
	getSprite(piece).setPosition((square % 8) * 135.f, 0.f);
	
	if (0 <= square && square <= 7)
	{
		getSprite(piece).setPosition(getSprite(piece).getPosition().x, 0.f);
	}
	else if (8 <= square && square <= 15)
	{
		getSprite(piece).setPosition(getSprite(piece).getPosition().x, 143.f);
	}
	else if (16 <= square && square <= 23)
	{
		getSprite(piece).setPosition(getSprite(piece).getPosition().x, 278.f);
	}
	else if (24 <= square && square <= 31)
	{
		getSprite(piece).setPosition(getSprite(piece).getPosition().x, 413.f);
	}
	else if (32 <= square && square <= 39)
	{
		getSprite(piece).setPosition(getSprite(piece).getPosition().x, 548.f);
	}
	else if (40 <= square && square <= 47)
	{
		getSprite(piece).setPosition(getSprite(piece).getPosition().x, 683.f);
	}
	else if (48 <= square && square <= 55)
	{
		getSprite(piece).setPosition(getSprite(piece).getPosition().x, 818.f);
	}
	else if (56 <= square && square <= 64)
	{
		getSprite(piece).setPosition(getSprite(piece).getPosition().x, 953.f);
	}
}

//takes the inputed piece and creates a sprite based off of the type and color of the piece
//then, adds the sprite to the map with the key being the inputed piece
sf::Sprite&
SpriteFactory::createSprite(Piece* piece)
{
	//first, converts the kind and color of the piece into usable values by the sprite sheet
    int kindIndex = this->getKindIndex(piece->getKind());

	//initializes the sprite
    sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect((16 * kindIndex), (16 * piece->getColor()), 16, 16));
	sprite.setScale(8.f, 8.f);

	//adds the sprite to the map
    _spriteMap[piece] = sprite;

    return _spriteMap[piece];
}



//i Made these
int
SpriteFactory::getKindIndex(Kind kind) const
{
    switch (kind)
	{
	case A_PAWN:
	case B_PAWN:
	case C_PAWN:
	case D_PAWN:
	case E_PAWN:
	case F_PAWN:
	case G_PAWN:
	case H_PAWN:
		return 5;
	case Q_ROOK:
	case K_ROOK:
		return 0;
	case Q_KNIGHT:
	case K_KNIGHT:
		return 1;
	case Q_BISHOP:
	case K_BISHOP:
		return 2;
	case QUEEN:
	case A_X_QUEEN:
	case B_X_QUEEN:
	case C_X_QUEEN:
	case D_X_QUEEN:
	case E_X_QUEEN:
	case F_X_QUEEN:
	case G_X_QUEEN:
	case H_X_QUEEN:
		return 3;
	case KING:
		return 4;
	default:
        break;
	}
    return 0;
}
