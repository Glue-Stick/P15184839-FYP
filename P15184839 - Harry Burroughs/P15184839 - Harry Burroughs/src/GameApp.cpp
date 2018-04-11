#include <GameApp.h>

GameApp::GameApp()
{
	m_window = new sf::RenderWindow (sf::VideoMode(1400, 900, 32),""); /*!< Creates the sfml window the game will run in, at 1400 in the x and 900 in the y, created as a pointer so it will hold its place in the memory. */
	scene = new Scene();
	input = new Input(scene);
	
}

void GameApp::Run()
{
	ImGui::CreateContext();
	m_window->setVerticalSyncEnabled(true);
	ImGui::SFML::Init(m_window);

	sf::Color bgColor;

	float color[3] = { 0.f, 0.f, 0.f };
	float location[2] = { 700.f, 450.f };

	char windowTitle[255] = "Final Year Project";

	m_window->setTitle(windowTitle);
	m_window->resetGLStates();
	sf::Clock deltaClock;

	//main application loop
	while (m_window->isOpen())
	{
		//m_window->clear(sf::Color::White);

		//HANDLE EVENT MESSAGE FROM OS
		sf::Event e;
		while (m_window->pollEvent(e))
		{
			ImGui::SFML::ProcessEvent(e);
			if (e.type == sf::Event::Closed)
				m_window->close();
			//input->InputHandler(e, m_window);
		}	

		ImGui::SFML::Update(m_window, deltaClock.restart());

		ImGui::Begin("Sample Window"); //begin window

		//background colour edit
		if (ImGui::ColorEdit3("Background Colour", color))
		{
			//this code gets called if color value changes, so the background colour is upgraded automatically
			bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
			bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
			bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
		}

		//winodw title text edit
		ImGui::InputText("Window title", windowTitle, 255);

		if (ImGui::Button("Update window title"))
		{
			//this code gets if user clicks on the button
			m_window->setTitle(windowTitle);
		}
		ImGui::End();

		ImGui::Begin("Add Shapes");

		if (ImGui::Button("Add Red Square"))
		{
			input->draw->drawRedSquare(location[0], location[1], 20.f, m_window);
		}
		if (ImGui::Button("Add Blue Square"))
		{
			input->draw->drawBlueSquare(location[0] + 100, location[1] + 100, 20.f, m_window);
		}
		if (ImGui::Button("Add Yellow Square"))
		{
			input->draw->drawYellowSquare(location[0] - 100, location[1] - 100, 20.f, m_window);
		}

		ImGui::End();

		m_window->clear(bgColor);
		ImGui::SFML::Render(m_window);

		scene->render(m_window);
		//present it to that screen
		m_window->display();
	}
	ImGui::DestroyContext();
}


