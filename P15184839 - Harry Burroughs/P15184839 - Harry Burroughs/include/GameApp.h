#pragma once
#include <iostream>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\OpenGL.hpp>


class GameApp
{
public:
	GameApp();
	GameApp(const GameApp& other);
	GameApp& operator=(const GameApp&);
	virtual ~GameApp(void);

	//Main Application loop
	void Run();

	//Framework Methods
	virtual bool Init() = 0;
	virtual void Update(sf::Time& time) = 0;
	virtual void Render(sf::Time& time) = 0;
	virtual void Cleanup() = 0;

	sf::RenderWindow* m_window;

private:
	
	sf::Clock m_clock;
};