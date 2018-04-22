#pragma once
#include <Objects.h>


class Player : public Objects
{
public:
	Player(sf::Vector2f position, sf::Vector2f size, float rotation, sf::Color colour); /*!< Constructor that creates a player object on the window, determines object type and whether it can be affected by gravity */
	virtual void Update(float power, float speed); /*!> Update applys all physics movements to the player object such as gravity and collisions, as well as handling user input */
private:
protected:
};