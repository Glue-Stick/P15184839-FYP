#include "Objects.h"

Objects::Objects(sf::Vector2f position, sf::Vector2f size, sf::Color colour, bool updateVisual) : Collision(1, 1)
{
	m_position = position;
	m_size = size;
	update = updateVisual;

	drawable = new sf::RectangleShape(size);
	drawable->setOrigin(size.x / 2.0f, size.y / 2.0f);
	drawable->setPosition(position);
	drawable->setRotation(0);
	drawable->setFillColor(colour);
	drawable->setOutlineColor(sf::Color::Black);
	drawable->setOutlineThickness(1.f);
	
}

Objects::Objects(sf::Vector2f position, float radius, sf::Color colour, bool updateVisual) : Collision(1, 1)
{
	m_position = position;
	m_size = sf::Vector2f(radius, radius);
	update = updateVisual;

	drawable = new sf::CircleShape(radius);
	drawable->setOrigin(radius, radius);
	drawable->setPosition(position);
	drawable->setRotation(0);
	drawable->setFillColor(colour);
	drawable->setOutlineColor(sf::Color::Black);
	drawable->setOutlineThickness(1.f);
}

Objects::Objects(sf::Vector2f position, float radius, float numberOfPoints, sf::Color colour, bool updateVisual) : Collision(1, 1)
{
	m_position = position;
	m_size = sf::Vector2f(radius, radius);
	update = updateVisual;

	drawable = new sf::CircleShape(radius, numberOfPoints);
	drawable->setOrigin(radius, radius);
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

void Objects::Update(float power)
{
	drawable->setPosition(m_position);
	Collision::Update(power);
	if (update)
	{
		move();
	}
}
