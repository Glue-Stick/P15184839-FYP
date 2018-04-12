#pragma once
#include <iostream>
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

	void drawPlayer(float x, float y, float size, sf::RenderWindow* window);

	void drawGrid(float x, float y, sf::RenderWindow* window);
	void drawGridNumbers(float x, float y, sf::RenderWindow* window);

	sf::Font Font;
private:
protected:
};