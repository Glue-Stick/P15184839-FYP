#include "Input.h"

Input::Input()
{
	
}

void Input::InputHandler(sf::Event event, sf::RenderWindow* window)
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed && sf::Keyboard::LShift)
		{
			std::cout << "Left Shift" << std::endl;
			//draw.drawSquare(700, 450, window);			
		}
	}
}
