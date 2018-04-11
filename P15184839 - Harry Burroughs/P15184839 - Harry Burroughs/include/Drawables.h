#pragma once
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <vector>
#include <Scene.h>


class Drawables
{
public:
	Scene* scene;
	Drawables(Scene* scene);
	void drawRedSquare(float x, float y, float size, sf::RenderWindow* window);
	void drawBlueSquare(float x, float y, float size, sf::RenderWindow* window);
	void drawYellowSquare(float x, float y, float size, sf::RenderWindow* window);
private:
protected:
};