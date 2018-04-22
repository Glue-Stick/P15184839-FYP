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

	void drawSquare(float x, float y, float size, float rotation, sf::RenderWindow* window, sf::Color color); /*!< Function that applies the variables determined by the player in the main loop, and applies those variables to an Object constructor, and adds the Object to the shapesToBeDrawn array in the Scene class */
	void drawRectangle(float x, float y, float size, float rotation, sf::RenderWindow* window, sf::Color color); /*!< Function that applies the variables determined by the player in the main loop, and applies those variables to an Object constructor, and adds the Object to the shapesToBeDrawn array in the Scene class */
	void drawCircle(float x, float y, float size, float rotation, sf::RenderWindow* window, sf::Color color); /*!< Function that applies the variables determined by the player in the main loop, and applies those variables to an Object constructor, and adds the Object to the shapesToBeDrawn array in the Scene class */
	void drawTriangle(float x, float y, float size, float rotation, sf::RenderWindow* window, sf::Color color); /*!< Function that applies the variables determined by the player in the main loop, and applies those variables to an Object constructor, and adds the Object to the shapesToBeDrawn array in the Scene class */

	void drawGrid(float x, float y, sf::RenderWindow* window); /*!< Function that sets the line positions of the grid and adds those drawables to the gridToBeDrawn array in Scene */
	void drawGridNumbers(float x, float y, sf::RenderWindow* window); /*!< Function that sets the numbers and their positions on the grid and adds those to the gridToBeDrawn array in Scene */

	sf::Font Font; /*!< Determines the font that will be used by the numbers that appear on the grid */
private:
	
protected:
};