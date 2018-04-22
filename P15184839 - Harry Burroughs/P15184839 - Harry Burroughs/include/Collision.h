#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>

class Collision
{
public: 
	Collision(bool applyGravity, bool staticObject); /*!< Constructor called to determine whether the object made will have gravity applied to it and whether it will be a static object */
	~Collision();

	void Move(float dx, float dy) { applyForce(sf::Vector2f(dx, dy), 20); } /*!< The Move function is used to apply a force to objects that are colliding with each other, and prevent them from falling through each other */

	bool checkCollision(Collision& other, float push); /*!< Function that checks if an object is colliding with another object, and moves the object should they be intersecting */
	sf::Vector2f GetPosition() { return m_position; } /*!< Returns the position of an object on the window */
	sf::Vector2f GetHalfSize() { return m_size / 2.0f; } /*!< Returns the half size of an object on the window */
	sf::Vector2f GetSize() { return m_size; } /*!< Returns the size of an object on the window */
	float getRotation() { return m_rotation; } /*!< Returns the rotation of an object on the window */
	sf::Color getColour() { return m_colour; } /*!< Returns the colour values of an object on the window */
	
	void applyForce(sf::Vector2f direction, float power); /*!< Function that checks to see if an object is static, and if it isn't it applies a velocity to the object */

	bool m_Gravity; /*!< Boolean used to determine if an object has gravity applied to it, and if it can it allows the update function to apply a force to the object */
	bool m_staticCollider; /*!< Boolean used to determine if an object can be affected by forces or not, if it can, velocity can be applied to the object */
	bool isGrounded = false; /*!< Boolean used to determine if an object is against another object, used to determine player jumping and whether gravity still needs to be applied */

	void isStatic(bool wontMove); /*!< Function used by the Player to set the object as notStatic */

	sf::Vector2f m_velocity; /*!< Variable used to set the velocity to be applied to an object */

	void move(); /*!< Function used to update the position of the player after velocity has been applied */

private:
	
protected:
	sf::Vector2f m_position; /*!< Variable that holds the X and Y coordinates of an object */
	sf::Vector2f m_size; /*!< Varbiable that holds the X and Y values for the size of an object */
	float m_rotation; /*!< Variable that holds the rotation value for an object */
	sf::Color m_colour; /*!< Variable that holds the R, G, B values of an object */

	virtual void Update(float power); /*!< Update function that applies all movements to do with physics to an objkect drawn to the window, power can be adjusted by the user in the window */
	
};