#pragma once
#include<SFML\Graphics.hpp>

class Collision
{
public: 
	Collision();
	~Collision();

	void Move(float dx, float dy) { body->move(dx, dy); }

	bool checkCollision(Collision& other, float push);
	sf::Vector2f GetPosition() { return body->getPosition(); }
	sf::Vector2f GetHalfSize() { return body->getSize() / 2.0f; }
private:
	sf::RectangleShape* body;
	
protected:
	sf::Vector2f m_position;
	sf::Vector2f m_size;
};