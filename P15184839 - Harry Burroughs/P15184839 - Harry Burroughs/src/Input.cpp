#include "Input.h"

Input::Input(Scene* scene)
{
	draw = new Drawables(scene);
}

void Input::InputHandler(sf::Event event, sf::RenderWindow* window)
{
	if (event.type == sf::Event::KeyPressed && sf::Keyboard::LShift)
	{
				
	}
	
}
