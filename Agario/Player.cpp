#include "Player.h"

void Player::initVariables()
{
	movementSpeed = 5.0f;
}

void Player::initShape()
{
	shape.setFillColor(sf::Color::Green);
	shape.setSize(sf::Vector2f(50.f, 50.f));
}

//Player::Player()
//{
//	initVariables();
//	initShape();
//}

Player::Player(float x, float y)
{
	shape.setPosition(x, y);
	initVariables();
	initShape();
}

Player::~Player()
{

}

void Player::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		shape.move(-movementSpeed, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		shape.move(movementSpeed, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		shape.move(0, -movementSpeed);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		shape.move(0, movementSpeed);
	}
}

void Player::updateWindowBoundsCollision(const sf::RenderTarget* target)
{
	sf::Vector2u screenDimensions = target->getSize();

	// Left
	if (shape.getGlobalBounds().left <= 0.f)
		shape.setPosition(0.f, shape.getGlobalBounds().top);
	// Right
	else if (shape.getGlobalBounds().left + shape.getGlobalBounds().width >= screenDimensions.x)
		shape.setPosition(screenDimensions.x - shape.getGlobalBounds().width, shape.getGlobalBounds().top);

	// Top
	if (shape.getGlobalBounds().top <= 0.f)
		shape.setPosition(shape.getGlobalBounds().left, 0);
	// Bottom
	else if (shape.getGlobalBounds().top + shape.getGlobalBounds().height >= screenDimensions.y)
		shape.setPosition(shape.getGlobalBounds().left, screenDimensions.y - shape.getGlobalBounds().height);
}

void Player::update(const sf::RenderTarget* target)
{
	updateInput();
	updateWindowBoundsCollision(target);
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(shape);
}


