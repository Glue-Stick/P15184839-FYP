#pragma once
#include <SFML\Graphics.hpp>
#include <Collision.h>

class Objects : public sf::Drawable, public Collision
{
public:
	Objects(sf::Vector2f position, sf::Vector2f size, float rotation, sf::Color colour, bool updateVisual);	/*!< Constructor that creates a physics body and shape for an object to be drawn to the screen, takes in values for Drawables to define the parameters of the object */
	Objects(sf::Vector2f position, float radius, sf::Color colour, bool updateVisual); /*!< Constructor that creates a physics body and shape for an object to be drawn to the screen, takes in values for Drawables to define the parameters of the object */
	Objects(sf::Vector2f position, float radius, float rotation, float numberOfPoints, sf::Color colour, bool updateVisual); /*!< Constructor that creates a physics body and shape for an object to be drawn to the screen, takes in values for Drawables to define the parameters of the object */
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; /*!<  */

	virtual void Update(float power) override; /*!< Calls the update function in Collisions and allows Update to be called from the Player class */
	bool update; /*!< Boolean to determine whether the drawn shape of the object should be updated after being moved by physics */

	int type; /*!< Integer that defines the type of an object to allow for easy identification when read from a save file */

	sf::Shape* getDrawable() { return drawable; } /*!< Returns the drawable of an object created */
private:
	sf::Shape* drawable; /*!< Pointer to a drawable type that is reused every time a new object is created and drawn to the window */
protected:

};