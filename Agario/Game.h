#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include "Player.h"
#include "Orb.h"

class Game
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event sfmlEvent;

	Player player;
	int points;

	sf::Font font;
	sf::Text guiText;

	std::vector<Orb> orbsVector;
	float spawnTimerMax;
	float spawnTimer;
	int maxOrbs;

	void initVariables();
	void initWindow();
	void initFont();
	void initText();

public:
	// Constructors and Destructors
	Game();
	~Game();

	// Accessors

	// Modifiers

	// Functions
	const bool running() const;
	void pollEvents();
	void spawnOrbs();
	void updateCollisions();
	void updateGUI();
	void update();
	void renderGUI(sf::RenderTarget* target);
	void render();
};

