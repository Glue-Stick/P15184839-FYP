#include <Player.h>

Player::Player(sf::Vector2f position, sf::Vector2f size, float rotation, sf::Color colour) : Objects(position, size, rotation, colour, false)
{
	isStatic(false);
	type = 4;
}

void Player::Update(float power, float speed)
{
	Objects::Update(power);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		applyForce(sf::Vector2f(-1, 0), speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		applyForce(sf::Vector2f(1, 0), speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && isGrounded)
	{
		applyForce(sf::Vector2f(0, -1), speed);
	}
	Objects::move();
}