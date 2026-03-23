#include "Game.h"

void Game::initVariables()
{
	window = nullptr;
	endGame = false;
}

void Game::initWindow()
{
	videoMode = sf::VideoMode(800, 600);
	window = new sf::RenderWindow(videoMode, "Agario", sf::Style::Close | sf::Style::Titlebar);
	window->setFramerateLimit(60);
}

// Constructors and Destructors
Game::Game()
{
	initVariables();
	initWindow();
}

Game::~Game()
{
	delete window;
}

const bool Game::running() const
{
	return window->isOpen();
}

void Game::pollEvents()
{
	while (window->pollEvent(sfmlEvent))
	{
		switch (sfmlEvent.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (sfmlEvent.key.code == sf::Keyboard::Escape)
				window->close();
			break;
		}
	}
}

void Game::update()
{
	pollEvents();
	player.update(window);
}

void Game::render()
{
	window->clear();
	// Render
	player.render(window);
	window->display();
}

// Functions