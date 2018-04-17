#pragma once
#include <SFML\Graphics.hpp>
#include <Collision.h>

class Objects : public sf::Drawable, Collision
{
public:
	Objects(sf::Vector2f position, sf::Vector2f size, sf::Color colour);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::Shape* drawable;
protected:

};