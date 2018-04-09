#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>


int main()
{
	sf::Window window(sf::VideoMode(800, 600), "Final Year Project");

	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				window.close();
		}
	}

	return 0;
}