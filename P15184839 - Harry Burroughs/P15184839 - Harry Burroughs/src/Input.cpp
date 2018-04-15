#include "Input.h"

Input::Input(Scene* scene)
{
	draw = new Drawables(scene);
}

void Input::InputHandler(sf::Event event, sf::RenderWindow* window)
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
