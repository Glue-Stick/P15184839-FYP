#include "GameApp.h"

GameApp::GameApp()
{
	m_window = new sf::RenderWindow(sf::VideoMode(1400, 900, 32),"Final Year Project"); /*!< Creates the sfml window the game will run in, at 1400 in the x and 900 in the y, created as a pointer so it will hold its place in the memory. */
}

GameApp::~GameApp(void)
{
}

void GameApp::Run()
{
	//Initialise app
	if (!Init())
	{
		std::cerr << "Error Intitialising Application [GameApp.cpp L17] Exiting" << std::endl;
	}

	//main application loop
	while (m_window->isOpen())
	{
		//HANDLE EVENT MESSAGE FROM OS
		sf::Event e;
		while (m_window->pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				m_window->close();
			input->InputHandler(e, m_window);
			/*if (e.type == sf::Event::KeyPressed && sf::Keyboard::LShift)
			{
				std::cout << "Left Shift" << std::endl;
			}*/
		}
		
		sf::Time time = m_clock.restart();
		//Update
		Update(time);
		//Render
		Render(time);
		
		//present it to that screen
		m_window->display();
	}
	//Cleanup resources before exiting
	Cleanup();
}


