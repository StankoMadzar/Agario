#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

class Orb
{
private:
	sf::CircleShape shape;
	int type;
	void initShape(const sf::RenderWindow* window);

public:
	Orb(const sf::RenderWindow* window, int type);
	const int& getType() const;

	const sf::CircleShape& getShape() const;

	void update();
	void render(sf::RenderTarget* target);
};

enum OrbTypes {DEFAULT = 0, DAMAGING, HEALING, NROFTYPES};

