#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <vector>

class Scene
{
public:
	Scene();
	void addDrawable(sf::Drawable* shape);
	void render(sf::RenderWindow* window);
private:
	std::vector<sf::Drawable*> toBeDrawn;
protected:
};