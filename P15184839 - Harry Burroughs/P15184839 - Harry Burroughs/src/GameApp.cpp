#include <GameApp.h>

GameApp::GameApp() /*!< Creates the sfml window the game will run in, at 1400 in the x and 900 in the y, created as a pointer so it will hold its place in the memory. */
{
	m_window = new sf::RenderWindow (sf::VideoMode(1400, 900, 32),""); 
	scene = new Scene();
	input = new Input(scene);
	
}

void GameApp::Run() /*!< The main game loop, handles all the UI creation, and calls the update functions when the program allows them to be called */
{
	ImGui::CreateContext();
	m_window->setVerticalSyncEnabled(true);
	ImGui::SFML::Init(m_window);

	sf::Color bgColor = sf::Color::White;
	float color[3] = { 1.0f, 1.0f, 1.0f };
	
	float variables[4] = { 700.f, 450.f, 20.f, 0.f };
	float usedVariables[4];

	float physics[2] = { 9.8, 0 };
	float usedPhysics[2];

	char windowTitle[255] = "Final Year Project";

	m_window->setTitle(windowTitle);
	m_window->resetGLStates();
	sf::Clock deltaClock;

	//main application loop
	while (m_window->isOpen())
	{
		//HANDLE EVENT MESSAGE FROM OS
		sf::Event e;
		while (m_window->pollEvent(e))
		{
			ImGui::SFML::ProcessEvent(e);
			if (e.type == sf::Event::Closed)
				m_window->close();
			
		}	

		ImGui::SFML::Update(m_window, deltaClock.restart());

		//only available if the mode is in level editor
		if (gameMode == true)
		{
			ImGui::Begin("Sample Window"); //begin window

										   //object colour edit
			if (ImGui::ColorEdit3("Object Colour", color))
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

			ImGui::Begin("Add Shapes: X, Y, Size, Rotation");

			if (ImGui::InputFloat4("Variable Input", variables))
			{
				usedVariables[0] = static_cast<sf::Uint8>(variables[0] * 1.f);
				usedVariables[1] = static_cast<sf::Uint8>(variables[1] * 1.f);
				usedVariables[2] = static_cast<sf::Uint8>(variables[2] * 1.f);
				usedVariables[3] = static_cast<sf::Uint8>(variables[3] * 1.f);
			}
			if (ImGui::Button("Add Square"))
			{
				input->draw->drawSquare(variables[0], variables[1], variables[2], variables[3], m_window, bgColor);				
			}
			if (ImGui::Button("Add Rectangle"))
			{
				input->draw->drawRectangle(variables[0], variables[1], variables[2], variables[3], m_window, bgColor);
			}
			if (ImGui::Button("Add Circle"))
			{
				input->draw->drawCircle(variables[0], variables[1], variables[2], variables[3], m_window, bgColor);
			}
			if (ImGui::Button("Add Triangle"))
			{
				input->draw->drawTriangle(variables[0], variables[1], variables[2], variables[3], m_window, bgColor);
			}
			if (scene->noOfPlayers < 1)
			{
				if (ImGui::Button("Add Player Square"))
				{
					scene->addPlayer(variables[0], variables[1], variables[2], variables[3], m_window, bgColor);
					noOfPlayers++;
				}
			}
			if (ImGui::Button("Undo"))
			{
				if (scene->shapesToBeDrawn.size() > 0)
				{
					scene->Undo();
				}
					
			}
			if (ImGui::Button("Clear Shapes"))
			{
				scene->clear();
				noOfPlayers = 0;
			}

			ImGui::End();

			ImGui::Begin("Save Level");

			if (ImGui::Button("Save Level to Slot 1"))
			{
				scene->save1();
				noOfPlayers = 0;
			}
			if (ImGui::Button("Save Level to Slot 2"))
			{
				scene->save2();
				noOfPlayers = 0;
			}
			if (ImGui::Button("Save Level to Slot 3"))
			{
				scene->save3();
				noOfPlayers = 0;
			}

			ImGui::End();
		}

		ImGui::Begin("Physics: Gravity, Player Speed");

		if (ImGui::InputFloat2("Physics Input", physics))
		{
			usedPhysics[0] = static_cast<sf::Uint8>(physics[0] * 30.f);
			usedPhysics[1] = static_cast<sf::Uint8>(physics[1] * 1.f);
		}

		ImGui::End();

		ImGui::Begin("Load Level");

		if (ImGui::Button("Load Level from Slot 1"))
		{
			scene->load1();
			noOfPlayers = 1;
		}
		if (ImGui::Button("Load Level from Slot 2"))
		{
			scene->load2();
			noOfPlayers = 1;
		}
		if (ImGui::Button("Load Level from Slot 3"))
		{
			scene->load3();
			noOfPlayers = 1;
		}

		ImGui::End();

		ImGui::Begin("Swap Mode");
		if (ImGui::Button("Editor Mode"))
		{
			gameMode = true;
		}
		if (ImGui::Button("Test Level Mode"))
		{
			gameMode = false;
		}

		ImGui::End();

		m_window->clear(sf::Color::White);
		ImGui::SFML::Render(m_window);
		input->draw->drawGrid(700, 450, m_window);
		input->draw->drawGridNumbers(0, 0, m_window);

		//only detects input if mode is in test level mode
		if (gameMode == false)
		{
			input->InputHandler(e, m_window);
			scene->update(m_window, physics[0], physics[1]);
		}

		scene->render(m_window);
		
		//present it to that screen
		m_window->display();
	}
	ImGui::DestroyContext();
}


