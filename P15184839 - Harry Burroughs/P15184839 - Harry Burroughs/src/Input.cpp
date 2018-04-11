#include "Input.h"

Input::Input(Scene* scene)
{
	draw = new Drawables(scene);
}

void Input::InputHandler(sf::Event event, sf::RenderWindow* window)
{
	if (event.type == sf::Event::KeyPressed && sf::Keyboard::LShift)
	{
		/*std::cout << "Please enter your x cooridnate." << std::endl;
		int x,y;
		float size;
		std::cin >> x;
		std::cout << "Please enter your y coordinate." << std::endl;
		std::cin >> y;
		std::cout << "Please enter what size you want your recatangle to be." << std::endl;
		std::cin >> size;*/
		draw->drawSquare(700, 700, 50, window);			
	}
	
}
