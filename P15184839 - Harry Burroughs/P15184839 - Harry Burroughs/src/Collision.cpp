#include "Collision.h"

Collision::Collision(bool applyGravity, bool staticObject)
{
	m_Gravity = applyGravity;
	m_staticCollider = staticObject;
}

Collision::~Collision()
{
}

bool Collision::checkCollision(Collision & other, float push)
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
				/*Move(intersectX * (20.0f - push), 0.0f);
				other.Move(-intersectX * push, 0.0f);*/
				m_position.x -= intersectX + m_size.x;
				m_velocity = 0;
			}
			else if (deltaX < 0.0f && m_velocity.x > 0)
			{
				/*Move(-intersectX * (20.0f - push), 0.0f);
				other.Move(intersectX * push, 0.0f);*/
				m_position.x += intersectX - m_size.x;
				m_velocity = 0;
			}
		}
		else
		{
			if (deltaY > 0.0f && m_velocity.y < 0)
			{
				/*Move(0.0f, intersectY * (20.0f - push));
				other.Move(0.0f, -intersectY * push);*/

				m_position.y -= intersectY + m_size.y;
				m_velocity.y = 0;

			}
			else if (deltaY < 0.0f && m_velocity.y > 0)
			{
				/*Move(0.0f, -intersectY * (20.0f - push));
				other.Move(0.0f, intersectY * push);*/
				m_position.y += intersectY - m_size.y;
				m_velocity.y = 0;
			}
		}
		isGrounded = true;
		return true;
	}

	return false;
}

void Collision::applyForce(sf::Vector2f direction, float power)
{
	if (!m_staticCollider)
	{
		m_velocity += direction * power * (1.f / 60.f);
	}	
}

void Collision::isStatic(bool wontMove)
{
	m_staticCollider = wontMove;
}

void Collision::move()
{
	m_position += m_velocity;
}

void Collision::Update(float power)
{
	//m_velocity = sf::Vector2f(0.f,0.f);
	if (m_Gravity && !isGrounded)
	{
		applyForce(sf::Vector2f(0, 1), (power * 30.f));
	}
	
}
