#include "State.h"

class Game
{
private:
	sf::RenderWindow window;

	sf::Texture boardTexture;

	sf::Sprite backgroundBoard;

	sf::Clock clock;
	float dt;

	State gameState;
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

