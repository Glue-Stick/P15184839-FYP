#include "Input.h"

Input::Input(Scene* scene) /*!< Pointer to the Drawable class to allow functions to be called through it */
{
	draw = new Drawables(scene);
}

void Input::InputHandler(sf::Event event, sf::RenderWindow* window) /*!< Old way of checking for input, allowed for testing */
{
	if (event.type == sf::Event::KeyPressed && event.type == sf::Keyboard::W)
	{
		std::cout << "Jump" << std::endl;
	}
	if (event.type == sf::Event::KeyPressed && event.type == sf::Keyboard::W)
	{
		std::cout << "Left" << std::endl;
	}
	if (event.type == sf::Event::KeyPressed && event.type == sf::Keyboard::W)
	{
		std::cout << "Right" << std::endl;
	}
}
