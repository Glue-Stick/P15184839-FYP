#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <vector>
#include <Collision.h>
#include <Objects.h>
#include <Player.h>
#include <fstream>
#include <iterator>
#include <iostream>
#include <string>

class Scene
{
public:
	Scene(); /*!< Empty class constructr */
	Objects* object; /*!< Pointer to the Object class to be able to call the creation of new object in the load functions */
	void addDrawable(Objects* shape); /*!< Function that adds new object drawables to shapesToBeDrawn array which is being drawn to the window */
	void addToGrid(sf::Drawable* grid); /*!< Function that adds the lines to gridToBeDrawnArray to draw out the grid on the window */
	void Undo(); /*!< Removes the most recent object drawn to the window, and detects what type of object was removed */
	void addText(sf::Text* text); /*!< Function that adds the numbers of the grid to gridToBeDrawnArray to be drawn to the window */
	void render(sf::RenderWindow* window); /*!< Loops through arrays shapesToBeDrawn and gridToBeDrawn and draws everything held within the arrays to the window */
	void update(sf::RenderWindow* window, float power, float speed); /*!< Handles the updates for the window, looping through shapesToBeDrawn and checking for collisions, as well as handling player collisions */

	void addPlayer(float x, float y, float size, float rotation, sf::RenderWindow * window, sf::Color color); /*!< Adds a player to the drawing array increases the number of players currently existing, preventing more than one player object existing at one time */
	int noOfPlayers = 0; /*!< Integer that determines how many player objects already exist, if its greater than 0, no more players can be drawn */

	void clear(); /*!< Function that calls the clear function on the shapesToBeDrawn array, clearing the window of all shapes */
	
	void save1(); /*!< Function that writes the information found in shapesToBeDrawn to a text file saveLevel1 */
	void save2(); /*!< Function that writes the information found in shapesToBeDrawn to a text file saveLevel2 */
	void save3(); /*!< Function that writes the information found in shapesToBeDrawn to a text file saveLevel3 */

	void load1(); /*!< Function that reads the information stored in saveLevel1, setting the information in a loop, then using the information to call the correct object and draw it correctly to the window */
	void load2(); /*!< Function that reads the information stored in saveLevel2, setting the information in a loop, then using the information to call the correct object and draw it correctly to the window */
	void load3(); /*!< Function that reads the information stored in saveLevel3, setting the information in a loop, then using the information to call the correct object and draw it correctly to the window */

	std::vector<Objects*> shapesToBeDrawn; /*!< Array that holds objects and their position, scale, rotation and colour values, and is constantly drawn to the window */
	std::vector<sf::Drawable*> gridToBeDrawn; /*!< Array that holds the lines and numbers that make up the grid, and is constantly drawn to the window */

	Player* player = nullptr; /*!< Pointer to the Player class, used to call functions and constructors made in the class */
private:
	
protected:
};