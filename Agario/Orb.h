#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

class Orb
{
private:
	sf::CircleShape shape;

	void initShape(const sf::RenderWindow* window);

public:
	Orb(const sf::RenderWindow* window);

	void update();
	void render(sf::RenderTarget* target);
};

