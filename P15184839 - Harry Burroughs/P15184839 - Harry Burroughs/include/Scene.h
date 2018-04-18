#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <vector>
#include <Collision.h>
#include <Objects.h>
#include <Player.h>
#include <fstream>
#include <iterator>

class Scene
{
public:
	Scene();
	Objects* object;
	void addDrawable(Objects* shape);
	void addToGrid(sf::Drawable* grid);
	void Undo();
	void addText(sf::Text* text);
	void render(sf::RenderWindow* window);
	void update(sf::RenderWindow* window, float power, float speed);

	void addPlayer(float x, float y, float size, float rotation, sf::RenderWindow * window, sf::Color color);
	int noOfPlayers = 0;

	void clear();
	void save1();
	void save2();
	void save3();
	void load1();
	void load2();
	void load3();

	std::vector<Objects*> shapesToBeDrawn;
	std::vector<sf::Drawable*> gridToBeDrawn;
	std::vector<Objects*> Level1;
	std::vector<Objects*> Level2;
	std::vector<Objects*> Level3;

	Player* player = nullptr;
private:
	
protected:
};