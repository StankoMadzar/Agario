#include "Orb.h"

void Orb::initShape(const sf::RenderWindow* window)
{
	shape.setRadius(static_cast<float>(rand() % 10 + 10));
	sf::Color color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
	shape.setFillColor(color);
	shape.setPosition(
		sf::Vector2f(
			static_cast<float>(rand() % window->getSize().x - shape.getGlobalBounds().width),
			static_cast<float>(rand() % window->getSize().y - shape.getGlobalBounds().height)
		)
	);
}

Orb::Orb(const sf::RenderWindow* window)
{ 
	initShape(window);
}

void Orb::update()
{

}

void Orb::render(sf::RenderTarget* target)
{
	target->draw(shape);
}