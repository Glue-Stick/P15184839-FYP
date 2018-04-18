#pragma once
#include <Objects.h>


class Player : public Objects
{
public:
	Player(sf::Vector2f position, sf::Vector2f size, float rotation, sf::Color colour);
	virtual void Update(float power, float speed);
private:
protected:
};