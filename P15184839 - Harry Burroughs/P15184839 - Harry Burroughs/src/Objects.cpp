#include "Objects.h"

Objects::Objects(sf::Vector2f position, sf::Vector2f size, float rotation, sf::Color colour, bool updateVisual) : Collision(1, 1)
{
	m_position = position;
	m_size = size;
	m_rotation = rotation;
	m_colour = colour;

	update = updateVisual;

	type = 1;

	drawable = new sf::RectangleShape(size);
	drawable->setOrigin(size.x / 2.0f, size.y / 2.0f);
	drawable->setPosition(position);
	drawable->setRotation(rotation);
	drawable->setFillColor(colour);
	drawable->setOutlineColor(sf::Color::Black);
	drawable->setOutlineThickness(1.f);
	
}

Objects::Objects(sf::Vector2f position, float radius, sf::Color colour, bool updateVisual) : Collision(1, 1)
{
	m_position = position;
	m_size = sf::Vector2f(radius, radius);
	m_colour = colour;

	update = updateVisual;

	type = 2;

	drawable = new sf::CircleShape(radius);
	drawable->setOrigin(radius, radius);
	drawable->setPosition(position);
	drawable->setRotation(0);
	drawable->setFillColor(colour);
	drawable->setOutlineColor(sf::Color::Black);
	drawable->setOutlineThickness(1.f);
}

Objects::Objects(sf::Vector2f position, float radius, float rotation, float numberOfPoints, sf::Color colour, bool updateVisual) : Collision(1, 1)
{
	m_position = position;
	m_size = sf::Vector2f(radius, radius);
	m_rotation = rotation;
	m_colour = colour;
	update = updateVisual;

	type = 3;

	drawable = new sf::CircleShape(radius, numberOfPoints);
	drawable->setOrigin(radius, radius);
	drawable->setPosition(position);
	drawable->setRotation(rotation);
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
