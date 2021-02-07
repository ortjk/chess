#include "Piece.h"
#include <SFML/Graphics.hpp>


class Hitbox
{
public:

	Hitbox();
	virtual ~Hitbox();

	Square getSquareAtPoint(sf::Vector2i point);
private:
	std::map<Square, sf::IntRect> _boxMap;

};

