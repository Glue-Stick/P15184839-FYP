#include "Collision.h"

Collision::Collision(bool applyGravity, bool staticObject) /*!< Constructor sets whether or not  */
{
	m_Gravity = applyGravity;
	m_staticCollider = staticObject;
}

Collision::~Collision()
{
}

bool Collision::checkCollision(Collision & other, float push) /*!< All collision checks are handled and settled here, by finding the constraints of each object and checking to see if their X and Y values intersect, and if they do, they handle to collision */
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);

		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f && m_velocity.x < 0)
			{
				m_position.x -= intersectX + m_size.x;
				m_velocity.x = 0;
			}
			else if (deltaX < 0.0f && m_velocity.x > 0)
			{
				m_position.x += intersectX - m_size.x;
				m_velocity.x = 0;
			}
		}
		else
		{
			if (deltaY > 0.0f && m_velocity.y < 0)
			{
				m_position.y -= intersectY + m_size.y;
				m_velocity.y = 0;

			}
			else if (deltaY < 0.0f && m_velocity.y > 0)
			{
				m_position.y += intersectY - m_size.y;
				m_velocity.y = 0;
			}
		}
		isGrounded = true;
		return true;
	}
	isGrounded = false;
	return false;
}

void Collision::applyForce(sf::Vector2f direction, float power) /*!< Applies a velocity to an Objects body */
{
	if (!m_staticCollider)
	{
		m_velocity += direction * power * (1.f / 60.f);
	}	
}

void Collision::isStatic(bool wontMove) /*!< Returns a boolean to set an object as static or not static */
{
	m_staticCollider = wontMove;
}

void Collision::move() /*!< Moves the position of an object by the velocity */
{
	m_position += m_velocity;
}

void Collision::Update(float power) /*!< Applies gravity to an object that can have gravity applied to it */
{
	//m_velocity = sf::Vector2f(0.f,0.f);
	if (m_Gravity && !isGrounded)
	{
		applyForce(sf::Vector2f(0, 1), (power * 30.f));
	}
	
}
