#pragma once
#include <SFML\Graphics.hpp>
#include <Collision.h>

class Objects : public sf::Drawable, public Collision
{
public:
	Objects(sf::Vector2f position, sf::Vector2f size, sf::Color colour, bool updateVisual);	
	Objects(sf::Vector2f position, float radius, sf::Color colour, bool updateVisual);
	Objects(sf::Vector2f position, float radius, float numberOfPoints, sf::Color colour, bool updateVisual);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual void Update(float power) override;
	bool update;

	sf::Shape* getDrawable() { return drawable; }
private:
	sf::Shape* drawable;
protected:

};