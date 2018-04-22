#include <Player.h>

Player::Player(sf::Vector2f position, sf::Vector2f size, float rotation, sf::Color colour) : Objects(position, size, rotation, colour, true) /*!< Sets the parameters for the player as well as stating that gravity should affect the player */
{
	isStatic(false);
	type = 4;
}

void Player::Update(float power, float speed) /*!< Checks for key input to apply a velocity to the player, as well as updating the player in reference to gravity as well as movement */
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