#include "Orb.h"

void Orb::initShape(const sf::RenderWindow* window)
{
	shape.setRadius(static_cast<float>(rand() % 10 + 10));
	sf::Color color;
	switch (type)
	{
	case OrbTypes::DEFAULT:
		color = sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
		break;
	case OrbTypes::HEALING:
		color = sf::Color(sf::Color::Green);
		shape.setOutlineColor(sf::Color::White);
		shape.setOutlineThickness(3.f);
		break;
	case OrbTypes::DAMAGING:
		color = sf::Color(sf::Color::Red);
		shape.setOutlineColor(sf::Color::White);
		shape.setOutlineThickness(3.f);
		break;
	}
	shape.setFillColor(color);
	shape.setPosition(
		sf::Vector2f(
			static_cast<float>(rand() % window->getSize().x - shape.getGlobalBounds().width),
			static_cast<float>(rand() % window->getSize().y - shape.getGlobalBounds().height)
		)
	);
}

Orb::Orb(const sf::RenderWindow* window, int type)
{ 
	this->type = type;
	initShape(window);
}

const int& Orb::getType() const
{
	return type;
}

const sf::CircleShape& Orb::getShape() const
{
	return shape;
}


void Orb::update()
{

}

void Orb::render(sf::RenderTarget* target)
{
	target->draw(shape);
}