#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

class Player
{
private:
	sf::RectangleShape shape;

	float movementSpeed;

	void initVariables();
	void initShape();

public:
	Player(float x = 0, float y = 0);
	~Player();

	void updateInput();
	void updateWindowBoundsCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};

