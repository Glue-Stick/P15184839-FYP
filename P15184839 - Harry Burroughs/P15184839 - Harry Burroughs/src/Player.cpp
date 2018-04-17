#include <Player.h>

Player::Player(sf::Vector2f position, sf::Vector2f size, sf::Color colour) : Objects(position, size, colour, false)
{
	isStatic(false);
}

void Player::Update(float power, float speed)
{
	Objects::Update(power);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		applyForce(sf::Vector2f(-1, 0), speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		applyForce(sf::Vector2f(1, 0), speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		applyForce(sf::Vector2f(0, -1), speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		applyForce(sf::Vector2f(0, 1), speed);
	}
	Objects::move();
}