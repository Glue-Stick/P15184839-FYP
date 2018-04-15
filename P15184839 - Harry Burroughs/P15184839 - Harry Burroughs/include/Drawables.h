#pragma once
#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <Box2D\Box2D.h>
#include <vector>
#include <Scene.h>


class Drawables
{
public:
	Scene* scene;
	Drawables(Scene* scene);
	void drawRedSquare(float x, float y, float size, float rotation, sf::RenderWindow* window, sf::Color color);
	void drawBlueSquare(float x, float y, float size, float rotation, sf::RenderWindow* window, sf::Color color);
	void drawYellowSquare(float x, float y, float size, float rotation, sf::RenderWindow* window, sf::Color color);

	void drawPlayer(float x, float y, float size, float rotation, sf::RenderWindow* window, sf::Color color);

	void drawGrid(float x, float y, sf::RenderWindow* window);
	void drawGridNumbers(float x, float y, sf::RenderWindow* window);

	sf::Font Font;
private:
	
protected:
};