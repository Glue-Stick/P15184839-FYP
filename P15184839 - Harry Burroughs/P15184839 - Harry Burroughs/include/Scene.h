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
	void save1();
	void save2();
	void save3();
	void load1();
	void load2();
	void load3();
private:
	std::vector<sf::Drawable*> shapesToBeDrawn;
	std::vector<sf::Drawable*> gridToBeDrawn;
	std::vector<sf::Drawable*> Level1;
	std::vector<sf::Drawable*> Level2;
	std::vector<sf::Drawable*> Level3;
protected:
};