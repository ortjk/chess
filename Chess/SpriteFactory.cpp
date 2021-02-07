#include "SpriteFactory.h"
#include "Board.h"
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

void SpriteFactory::updatePosition(Piece* piece, Board::Square square)
{
	//BRACKETS ARE NEEDED FOR CASES BECAUSE OF TRANSFER OF CONTROL
	switch (square % 8)
	{
	case 0:
		getSprite(piece).setPosition(0, 0);
		break;
	case 1:
	{
		getSprite(piece).setPosition(135, 0);
	}	break;
	case 2:
	{
		getSprite(piece).setPosition(270, 0);
	}	break;
	case 3:
	{
		getSprite(piece).setPosition(405, 0);
	}	break;
	case 4:
	{
		getSprite(piece).setPosition(540, 0);
	}	break;
	case 5:
	{
		getSprite(piece).setPosition(675, 0);
	}	break;
	case 6:
	{
		getSprite(piece).setPosition(810, 0);
	}	break;
	case 7:
	{
		getSprite(piece).setPosition(945, 0);
	}	break;
	default:
		std::cout << "error in the file setting of the sprite\n";
		break;
	}
	

	if (0 <= square && square <= 7)
	{
		getSprite(piece).setPosition(getSprite(piece).getPosition().x, 945);
	}
	else if (8 <= square && square <= 15)
	{
		getSprite(piece).setPosition(getSprite(piece).getPosition().x, 810);
	}
	else if (16 <= square && square <= 23)
	{
		getSprite(piece).setPosition(getSprite(piece).getPosition().x, 675);
	}
	else if (24 <= square && square <= 31)
	{
		getSprite(piece).setPosition(getSprite(piece).getPosition().x, 540);
	}
	else if (32 <= square && square <= 39)
	{
		getSprite(piece).setPosition(getSprite(piece).getPosition().x, 405);
	}
	else if (40 <= square && square <= 47)
	{
		getSprite(piece).setPosition(getSprite(piece).getPosition().x, 270);
	}
	else if (48 <= square && square <= 55)
	{
		getSprite(piece).setPosition(getSprite(piece).getPosition().x, 135);
	}
	else if (56 <= square && square <= 64)
	{
		getSprite(piece).setPosition(getSprite(piece).getPosition().x, 0);
	}
	else
	{
		std::cout << "error in the rank setting of the sprite\n";
	}
}

//takes the inputed piece and creates a sprite based off of the type and color of the piece
//then, adds the sprite to the map with the key being the inputed piece
sf::Sprite&
SpriteFactory::createSprite(Piece* piece)
{
	//first, converts the kind and color of the piece into usable values by the sprite sheet
    int kindIndex = this->getKindIndex(piece->getKind());
    int colorIndex = this->getColorIndex(piece->getColor());

	//initializes the sprite
    sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect((16 * kindIndex), (16 * colorIndex), 16, 16));
	sprite.setScale(8.f, 8.f);

	//adds the sprite to the map
    _spriteMap[piece] = sprite;

    return _spriteMap[piece];
}



//i Made these
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