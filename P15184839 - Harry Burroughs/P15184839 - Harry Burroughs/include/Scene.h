#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <vector>

class Scene
{
public:
	Scene();
	void addDrawable(sf::Drawable* shape);
	void addText(sf::Text* text);
	void render(sf::RenderWindow* window);
	void clear();
	void save();
	void load();
private:
	std::vector<sf::Drawable*> shapesToBeDrawn;
	std::vector<sf::Drawable*> gridToBeDrawn;
	std::vector<sf::Drawable*> Level1;
protected:
};