#include "chessPiece.h"

class Game
{
private:
	sf::RenderWindow window;

	sf::Texture boardTexture;

	sf::Sprite backgroundBoard;

	sf::Clock clock;
	float dt;
public:

	//initializers
	void initVariables();

	//constructors/destructors
	Game();
	virtual ~Game();

	//functions
	void updateDt();

	void run();
};

