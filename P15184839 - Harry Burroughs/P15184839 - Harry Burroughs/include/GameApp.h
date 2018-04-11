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

class GameApp
{
public:
	Input* input;
	Scene* scene;
	GameApp();

	//Main Application loop
	void Run();

	sf::RenderWindow* m_window;

protected:
private:

};