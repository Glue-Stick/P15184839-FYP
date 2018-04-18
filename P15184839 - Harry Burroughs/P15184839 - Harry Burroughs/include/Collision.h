#pragma once
#include<SFML\Graphics.hpp>

class Collision
{
public: 
	Collision(bool applyGravity, bool staticObject);
	~Collision();

	void Move(float dx, float dy) { applyForce(sf::Vector2f(dx, dy), 10); }

	bool checkCollision(Collision& other, float push);
	sf::Vector2f GetPosition() { return m_position; }
	sf::Vector2f GetHalfSize() { return m_size / 2.0f; }
	
	void applyForce(sf::Vector2f direction, float power);

	bool m_Gravity;
	bool m_staticCollider;
	bool isGrounded = false;

	void isStatic(bool wontMove);

	sf::Vector2f m_velocity;

	void move();

private:
	sf::RectangleShape* body;
	
protected:
	sf::Vector2f m_position;
	sf::Vector2f m_size;

	virtual void Update(float power);
	
};