#include "Game.h"

//creates window, loads the board texture and the sprite is set to it, board is scaled up, and the delta time float is set to 0
void Game::initVariables()
{
	window.create(sf::VideoMode(1080, 1080), "Chess", sf::Style::Default);

	if (!boardTexture.loadFromFile("resources/Sprite-0001.png")) {
		std::cout << "ERROR COULD NOT LOAD BOARD TEXTURE\n";
	}

	backgroundBoard.setTexture(boardTexture);
	backgroundBoard.setScale(sf::Vector2f(34.f, 34.f));

	dt = 0.f;
}

Game::Game()
{
	initVariables();
}

Game::~Game()
{

}

//updates the dt float with how long it took to render a frame. not sure if ill need to use it but it's normally meant for animation & smooth movement
void Game::updateDt()
{
	dt = clock.restart().asSeconds();
}

void Game::run()
{
	//black pawn is created for example
	ChessPiece bPawn(ChessPiece::PAWN, ChessPiece::BLACK_PIECE, 1, 7);

	//main game loop, everything inside is repeated for as long as window is open
	while (window.isOpen())
	{
		updateDt();

		//sf event is a queue for all actions input by the user, and if any of these events are the window closing, the window is closed
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		//if the piece's hitbox is moused over and is left clicked, it will follow the mouse
		if (bPawn.getHitrect().contains(sf::Mouse::getPosition(window)) &&
			sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			bPawn.setSpritePos(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
		}

		//the making of one frame:
		//clears the window and paints it black
		window.clear(sf::Color::Black);

		//draws the sprites input
		window.draw(backgroundBoard);
		window.draw(bPawn.getSprite());

		//displays all of the stuff that has been drawn
		window.display();
	}
}
