#include "Objects.h"

Objects::Objects(sf::Vector2f position, sf::Vector2f size, sf::Color colour) : Collision()
{
	m_position = position;
	m_size = size;

	drawable = new sf::RectangleShape(size);
	drawable->setOrigin(size.x / 2.0f, size.y / 2.0f);
	drawable->setPosition(position);
	drawable->setRotation(0);
	drawable->setFillColor(colour);
	drawable->setOutlineColor(sf::Color::Black);
	drawable->setOutlineThickness(1.f);
	
}

void Objects::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*drawable);
}
