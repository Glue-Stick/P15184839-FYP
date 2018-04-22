#include "Scene.h"

Scene::Scene()
{
	
}

void Scene::addDrawable(Objects* shape) /*!< When called will push back the passed in object to the array */
{
	shapesToBeDrawn.push_back(shape); 
}

void Scene::addToGrid(sf::Drawable * grid) /*!< When called will push back the passed in drawable to the array */
{
	gridToBeDrawn.push_back(grid); 
}

void Scene::Undo() /*!< Clears the last thing to be pushed into the array, and if they type of the object matches the player type, it resets the noOfPlayers variablee */
{
	if (shapesToBeDrawn[shapesToBeDrawn.size() - 1]->type == 2)
	{
		noOfPlayers = 0;
	}
	shapesToBeDrawn.pop_back();
}

void Scene::addText(sf::Text* text) /*!< When called will push back the passed in text to the array */
{
	gridToBeDrawn.push_back(text);
}

void Scene::render(sf::RenderWindow* window) /*!< Loops through the arrays every frame and renders the shape to the window */
{
	for (unsigned int i = 0; i < shapesToBeDrawn.size(); i++)
	{
		window->draw(*shapesToBeDrawn[i]->getDrawable());
	}
	for (unsigned int i = 0; i < gridToBeDrawn.size(); i++)
	{
		window->draw(*gridToBeDrawn[i]);
	}	
}

void Scene::update(sf::RenderWindow * window, float power, float speed) /*!< Loops through the array and updates every object, and if the player exists on the window, updates the player and checks for collisions with the player */
{
	for (int i = 0; i < shapesToBeDrawn.size(); i++)
	{
		shapesToBeDrawn[i]->Update(power);
	}
	if (noOfPlayers == 1)
	{
		player->Update(power, speed);
		for (int j = 0; j < shapesToBeDrawn.size(); j++)
		{
			player->checkCollision(*shapesToBeDrawn[j], 0);
		}
	}	
}

void Scene::addPlayer(float x, float y, float size, float rotation, sf::RenderWindow * window, sf::Color color) /*!< Adds the player object to the array and sets the noOfPlayers variable to be 1 */
{
	player = new Player(sf::Vector2f(x, y), sf::Vector2f(size, size), rotation, color);
	shapesToBeDrawn.push_back(player);
	noOfPlayers = 1;
}

void Scene::clear() /*!< Empties the array and resets the numbers of players  */
{
	shapesToBeDrawn.clear();
	noOfPlayers = 0;
}

void Scene::save1() /*!< Saves the shapesToBeDrawn array to a text file */
{
	std::ofstream output_file("./Levels/Level1.txt");
	for (int i = 0; i < shapesToBeDrawn.size(); i++)
	{
		output_file << "Object" << "\n";
		output_file << shapesToBeDrawn[i]->type << "\n";
		output_file << shapesToBeDrawn[i]->GetPosition().x << "\n";
		output_file << shapesToBeDrawn[i]->GetPosition().y << "\n";
		output_file << shapesToBeDrawn[i]->GetSize().x << "\n";
		output_file << shapesToBeDrawn[i]->GetSize().y << "\n";
		output_file << shapesToBeDrawn[i]->getRotation() << "\n";

		int r = shapesToBeDrawn[i]->getColour().r;
		int g = shapesToBeDrawn[i]->getColour().g;
		int b = shapesToBeDrawn[i]->getColour().b;

		output_file << r << "\n";
		output_file << g << "\n";
		output_file << b << "\n";
	}	
} 

void Scene::save2()
{
	std::ofstream output_file("./Levels/Level2.txt");
	for (int i = 0; i < shapesToBeDrawn.size(); i++)
	{
		output_file << "Object" << "\n";
		output_file << shapesToBeDrawn[i]->type << "\n";
		output_file << shapesToBeDrawn[i]->GetPosition().x << "\n";
		output_file << shapesToBeDrawn[i]->GetPosition().y << "\n";
		output_file << shapesToBeDrawn[i]->GetSize().x << "\n";
		output_file << shapesToBeDrawn[i]->GetSize().y << "\n";
		output_file << shapesToBeDrawn[i]->getRotation() << "\n";
		
		int r = shapesToBeDrawn[i]->getColour().r;
		int g = shapesToBeDrawn[i]->getColour().g;
		int b = shapesToBeDrawn[i]->getColour().b;

		output_file << r << "\n";
		output_file << g << "\n";
		output_file << b << "\n";
	}	
}

void Scene::save3()
{
	std::ofstream output_file("./Levels/Level3.txt");
	for (int i = 0; i < shapesToBeDrawn.size(); i++)
	{
		output_file << "Object" << "\n";
		output_file << shapesToBeDrawn[i]->type << "\n";
		output_file << shapesToBeDrawn[i]->GetPosition().x << "\n";
		output_file << shapesToBeDrawn[i]->GetPosition().y << "\n";
		output_file << shapesToBeDrawn[i]->GetSize().x << "\n";
		output_file << shapesToBeDrawn[i]->GetSize().y << "\n";
		output_file << shapesToBeDrawn[i]->getRotation() << "\n";

		int r = shapesToBeDrawn[i]->getColour().r;
		int g = shapesToBeDrawn[i]->getColour().g;
		int b = shapesToBeDrawn[i]->getColour().b;

		output_file << r << "\n";
		output_file << g << "\n";
		output_file << b << "\n";
	}	
}

void Scene::load1() /*!< Reads the information from text file, writes that information to temporary variables and uses those variables to redraw the shapes saved to the window */
{
	//read from file
	std::ifstream input_file;
	input_file.open("./Levels/Level1.txt");


	//check for error
	if (input_file.fail())
	{
		std::cerr << "Error: Opening Save Level 1" << std::endl;
	}

	std::string check;
	int type;
	float posX;
	float posY;
	float sizeX;
	float sizeY;
	float rot;
	int r;
	int g;
	int b;

	std::string item;

	if (input_file.peek() == std::ifstream::traits_type::eof())
	{

	}
	else
	{
		while (!input_file.eof())
		{
			input_file >> check;
			if (check == "Object")
			{
				input_file >> type >> posX >> posY >> sizeX >> sizeY >> rot >> r >> g >> b;
			}

			if (type == 1)
			{
				addDrawable(new Objects(sf::Vector2f(posX, posY), sf::Vector2f(sizeX, sizeY), rot, sf::Color(r, g, b), 0));
			}
			if (type == 2)
			{
				addDrawable(new Objects(sf::Vector2f(posX, posY), sizeX, sf::Color(r, g, b), 0));
			}
			if (type == 3)
			{
				addDrawable(new Objects(sf::Vector2f(posX, posY), sizeX, rot, 3, sf::Color(r, g, b), 0));
			}
			if (type == 4)
			{
				player = new Player(sf::Vector2f(posX, posY), sf::Vector2f(sizeX, sizeY), rot, sf::Color(r, g, b));
				shapesToBeDrawn.push_back(player);
				noOfPlayers = 1;
			}
		}
	}

	
	
}

void Scene::load2()
{
	//read from file
	std::ifstream input_file;
	input_file.open("./Levels/Level2.txt");

	//check for error
	if (input_file.fail())
	{
		std::cerr << "Error: Opening Save Level 2" << std::endl;
	}

	std::string check;
	int type;
	float posX;
	float posY;
	float sizeX;
	float sizeY;
	float rot;
	int r;
	int g;
	int b;

	std::string item;
	if (input_file.peek() == std::ifstream::traits_type::eof())
	{

	}
	else
	{
		while (!input_file.eof())
		{
			input_file >> check;
			if (check == "Object")
			{
				input_file >> type >> posX >> posY >> sizeX >> sizeY >> rot >> r >> g >> b;
			}

			if (type == 1)
			{
				addDrawable(new Objects(sf::Vector2f(posX, posY), sf::Vector2f(sizeX, sizeY), rot, sf::Color(r, g, b), 0));
			}
			if (type == 2)
			{
				addDrawable(new Objects(sf::Vector2f(posX, posY), sizeX, sf::Color(r, g, b), 0));
			}
			if (type == 3)
			{
				addDrawable(new Objects(sf::Vector2f(posX, posY), sizeX, rot, 3, sf::Color(r, g, b), 0));
			}
			if (type == 4)
			{
				player = new Player(sf::Vector2f(posX, posY), sf::Vector2f(sizeX, sizeY), rot, sf::Color(r, g, b));
				shapesToBeDrawn.push_back(player);
				noOfPlayers = 1;
			}
		}
	}
}

void Scene::load3()
{
	//read from file
	std::ifstream input_file;
	input_file.open("./Levels/Level3.txt");

	//check for error
	if (input_file.fail())
	{
		std::cerr << "Error: Opening Save Level 3" << std::endl;
	}

	std::string check;
	int type;
	float posX;
	float posY;
	float sizeX;
	float sizeY;
	float rot;
	int r;
	int g;
	int b;

	std::string item;
	if (input_file.peek() == std::ifstream::traits_type::eof())
	{

	}
	else
	{
		while (!input_file.eof())
		{
			input_file >> check;
			if (check == "Object")
			{
				input_file >> type >> posX >> posY >> sizeX >> sizeY >> rot >> r >> g >> b;
			}

			if (type == 1)
			{
				addDrawable(new Objects(sf::Vector2f(posX, posY), sf::Vector2f(sizeX, sizeY), rot, sf::Color(r, g, b), 0));
			}
			if (type == 2)
			{
				addDrawable(new Objects(sf::Vector2f(posX, posY), sizeX, sf::Color(r, g, b), 0));
			}
			if (type == 3)
			{
				addDrawable(new Objects(sf::Vector2f(posX, posY), sizeX, rot, 3, sf::Color(r, g, b), 0));
			}
			if (type == 4)
			{
				player = new Player(sf::Vector2f(posX, posY), sf::Vector2f(sizeX, sizeY), rot, sf::Color(r, g, b));
				shapesToBeDrawn.push_back(player);
				noOfPlayers = 1;
			}
		}
	}
}
