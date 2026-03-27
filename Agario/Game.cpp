#include "Game.h"

void Game::initVariables()
{
	window = nullptr;
	endGame = false;
	spawnTimerMax = 10.f;
	spawnTimer = spawnTimerMax;
	maxOrbs = 15;
	points = 0;
}

void Game::initWindow()
{
	videoMode = sf::VideoMode(800, 600);
	window = new sf::RenderWindow(videoMode, "Agario", sf::Style::Close | sf::Style::Titlebar);
	window->setFramerateLimit(60);
}

void Game::initFont()
{
	if (!font.loadFromFile("Fonts/Arial.ttf"))
	{
		std::cerr << "Error when initializing fonts" << std::endl;
	}
}

void Game::initText()
{
	guiText.setFont(font);
	guiText.setCharacterSize(24);
	endGameText.setFont(font);
	endGameText.setCharacterSize(60);
	endGameText.setFillColor(sf::Color::Red);
	endGameText.setPosition(200, 300);
	endGameText.setString("GAME OVER");
}

// Constructors and Destructors
Game::Game()
{
	initVariables();
	initWindow();
	initFont();
	initText();
}

Game::~Game()
{
	delete window;
}

const bool Game::getEndGame() const
{
	return endGame;
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

void Game::spawnOrbs()
{
	if (spawnTimer < spawnTimerMax)
		spawnTimer += 4.f;
	else
	{
		if (orbsVector.size() <= maxOrbs)
		{
			orbsVector.push_back(Orb(window, randomizeOrbType()));
			spawnTimer = 0.f;
		}
	}
}

const int Game::randomizeOrbType()
{
	int type = OrbTypes::DEFAULT;
	int randValue = rand() % 100 + 1;

	if (randValue > 70 && randValue <= 85)
		type = OrbTypes::DAMAGING;
	else if (randValue > 85 && randValue <= 100)
		type = OrbTypes::HEALING;

	return type;
}

void Game::updatePlayer()
{
	player.update(window);
	if (player.getHp() <= 0)
		endGame = true;
}

void Game::updateCollisions()
{
	for (size_t i = 0; i < orbsVector.size(); i++)
	{
		if (player.getShape().getGlobalBounds().intersects(orbsVector[i].getShape().getGlobalBounds()))
		{
			switch (orbsVector[i].getType())
			{
			case OrbTypes::DEFAULT:
				points += 10;
				break;
			case OrbTypes::DAMAGING:
				player.takeDamage(2);
				break;
			case OrbTypes::HEALING:
				player.gainHealth(1);
				break;
			}
			orbsVector.erase(orbsVector.begin() + i);
		}
	}
}

void Game::updateGUI()
{
	std::stringstream ss;
	ss << "Points: " << points << '\n' << "Health: " << player.getHp() << '\n';
	guiText.setString(ss.str());
}

void Game::update()
{
	pollEvents();
	if (endGame == false)
	{
		spawnOrbs();
		updatePlayer();
		updateCollisions();
		updateGUI();
	}
}

void Game::renderGUI(sf::RenderTarget* target)
{
	target->draw(guiText);
}

void Game::render()
{
	window->clear();
	// Render
	player.render(window);

	for (auto& orb : orbsVector)
	{
		orb.render(window);
	}

	renderGUI(window);

	if (endGame)
		window->draw(endGameText);

	window->display();
}

// Functions