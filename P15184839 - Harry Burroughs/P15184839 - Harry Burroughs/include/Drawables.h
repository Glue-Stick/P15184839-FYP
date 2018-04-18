#pragma once
#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <vector>
#include <Scene.h>
#include <Collision.h>
#include <Objects.h>



class Drawables
{
public:
	Scene* scene;
	Drawables(Scene* scene);

	void drawSquare(float x, float y, float size, float rotation, sf::RenderWindow* window, sf::Color color);
	void drawRectangle(float x, float y, float size, float rotation, sf::RenderWindow* window, sf::Color color);
	void drawCircle(float x, float y, float size, float rotation, sf::RenderWindow* window, sf::Color color);
	void drawTriangle(float x, float y, float size, float rotation, sf::RenderWindow* window, sf::Color color);

	void drawGrid(float x, float y, sf::RenderWindow* window);
	void drawGridNumbers(float x, float y, sf::RenderWindow* window);

	sf::Font Font;
private:
	
protected:
};