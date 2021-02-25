#include "Game.h"
#include <iostream>

//creates window, loads the board texture and the sprite is set to it, board is scaled up, and the delta time float is set to 0
void Game::initVariables()
{
	window.create(sf::VideoMode(1080, 1080), "Chess", sf::Style::Default);

	if (!boardTexture.loadFromFile("resources/Sprite-0001.png")) 
	{
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

//updates the dt float with how long it took to render a frame. not sure if i'll need to use it but it's normally meant for animation & smooth movement
void Game::updateDt()
{
	dt = clock.restart().asSeconds();
}

void Game::run()
{
	gameState.reset();

	//main game loop, everything inside is repeated for as long as window is open
	while (window.isOpen())
	{
		updateDt();

		sf::IntRect rect(0, 0, 135, 135);

		//sf event is a queue for all actions input by the user, and if any of these events are the window closing, the window is closed
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					gameState.squareClicked(sf::Mouse::getPosition(window));
				}
				break;
			case sf::Event::MouseButtonReleased:
				gameState.squareReleased(sf::Mouse::getPosition(window));
				break;
			default:
				break;
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			gameState.pieceToMousePos(sf::Mouse::getPosition(window));
		}

		//the making of one frame:
		//clears the window and paints it black
		window.clear(sf::Color::Black);

		//draws the sprites input
		window.draw(backgroundBoard);

		for (int c = 0; c < COLOR_COUNT; c++)
		{
			for (int p = 0; p < KIND_COUNT; p++)
			{
				window.draw(gameState.getSprite((Color)c, (Kind)p));
			}
		}


		//displays all of the stuff that has been drawn
		window.display();
	}
}
