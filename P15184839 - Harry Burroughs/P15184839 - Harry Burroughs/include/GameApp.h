#pragma once
#include <iostream>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\Graphics\Shader.hpp>
#include <SFML\OpenGL.hpp>
#include "Scene.h"
#include "Input.h"
#include <imgui-master\imgui.h>
#include <imgui-master\imgui-SFML.h>

class GameApp
{
public:
	Input* input; /*!< Pointer to the Input Class which is used to call the drawing functions called when a button is pressed */
	Scene* scene; /*!< Pointer to the Scene Class so that the save, load, clear, undo, update and render functions can be called in the main game loop */
	//Collision* collision; /*!< P */
	GameApp(); /*!< Constructor to set the pointers of the classes called and set the name and size of the window created */

	//Main Application loop
	void Run(); /*!< Main application loop for the project */
	bool gameMode = true; /*!< Boolean that determines whether the project is in editor or play mode */

	sf::RenderWindow* m_window; /*!< Pointer to the window so that the objects can be drawn to the correct window from another class */
	int noOfPlayers = 0; /*!< Integer to determine whether the draw player button should exist on the window */	
protected:
private:

};