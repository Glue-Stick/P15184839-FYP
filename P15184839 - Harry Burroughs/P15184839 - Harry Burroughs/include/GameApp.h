#pragma once
#include <iostream>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\OpenGL.hpp>
#include "Scene.h"
#include <Input.h>
#include <imgui-master\imgui.h>
#include <imgui-master\imgui-SFML.h>
#include <Box2D\Box2D.h>

class GameApp
{
public:
	Input* input;
	Scene* scene;
	GameApp();

	//Main Application loop
	void Run();
	bool gameMode = true;

	sf::RenderWindow* m_window;
	int noOfPlayers = 0;

	
protected:
private:

};