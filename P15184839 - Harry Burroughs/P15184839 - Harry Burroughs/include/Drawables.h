#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <vector>
#include <Scene.h>


class Drawables
{
public:
	Scene* scene;
	Drawables(Scene* scene);
	void drawSquare(float x, float y, float size, sf::RenderWindow* window);
private:
protected:
};