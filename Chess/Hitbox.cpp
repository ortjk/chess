#include "Hitbox.h"
#include <iostream>

Hitbox::Hitbox()
{
	//creates 64 rects alligned with each square on the board, then puts both in a map accordingly
	sf::IntRect rect(sf::Vector2i(0, 0), sf::Vector2i(135, 135));

	for (int i = 0; i <= 63; i++)
	{
		rect.left = ((i % 8) * 135);
		if (0 <= i && i <= 7)
		{
			rect.top = 0;
		}
		else if (8 <= i && i <= 15)
		{
			rect.top = 135;
		}
		else if (16 <= i && i <= 23)
		{
			rect.top = 270;
		}
		else if (24 <= i && i <= 31)
		{
			rect.top = 405;
		}
		else if (32 <= i && i <= 39)
		{
			rect.top = 540;
		}
		else if (40 <= i && i <= 47)
		{
			rect.top = 675;
		}
		else if (48 <= i && i <= 55)
		{
			rect.top = 810;
		}
		else if (56 <= i && i <= 64)
		{
			rect.top = 945;
		}
		else
		{
			std::cout << "error in the hitbox generation\n";
		}

		_boxMap[Square(i)] = rect;
	}
}

Hitbox::~Hitbox()
{

}

Square Hitbox::getSquareAtPoint(sf::Vector2i point)
{
	for (int i = 0; i <= 63; i++)
	{
		sf::IntRect rect = _boxMap.at(Square(i));
		if (rect.contains(point))
		{
			return Square(i);
		}
	}
	return Square(64);
}

