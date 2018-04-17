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
	Input* input;
	Scene* scene;
	Collision* collision;
	GameApp();

	//Main Application loop
	void Run();
	bool gameMode = true;

	sf::RenderWindow* m_window;
	int noOfPlayers = 0;

	sf::Shader unshadowShader;
	sf::Shader lightOverShapeShader;

	

	
protected:
private:

};