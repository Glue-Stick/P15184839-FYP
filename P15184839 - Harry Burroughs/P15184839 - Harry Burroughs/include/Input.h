#pragma once
#include <iostream>
#include <Drawables.h>
#include <SFML\Window.hpp>

class Input
{
public:
	Input();
	void InputHandler(sf::Event event, sf::RenderWindow* window);

	Drawables draw;

private:

protected:
};


