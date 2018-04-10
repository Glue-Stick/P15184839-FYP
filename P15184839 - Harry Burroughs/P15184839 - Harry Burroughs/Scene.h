#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <vector>

class Scene
{
public:
	void addDrawable(sf::Drawable* shape);
private:
	std::vector<sf::Drawable*> toBeDrawn = std::vector<sf::Drawable*>();
protected:
};