#include "Scene.h"

Scene::Scene()
{
	
}

void Scene::addDrawable(Objects* shape)
{
	shapesToBeDrawn.push_back(shape);
}

void Scene::addToGrid(sf::Drawable * grid)
{
	gridToBeDrawn.push_back(grid);
}

void Scene::Undo()
{
	if (shapesToBeDrawn[shapesToBeDrawn.size() - 1]->type == 2)
	{
		noOfPlayers = 0;
	}
	shapesToBeDrawn.pop_back();
}

void Scene::addText(sf::Text* text)
{
	gridToBeDrawn.push_back(text);
}

void Scene::render(sf::RenderWindow* window)
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

void Scene::update(sf::RenderWindow * window, float power, float speed)
{
	for (int i = 0; i < shapesToBeDrawn.size(); i++)
	{
		shapesToBeDrawn[i]->Update(power);
	}
	if (player != nullptr)
	{
		player->Update(power, speed);
		for (int j = 0; j < shapesToBeDrawn.size(); j++)
		{
			player->checkCollision(*shapesToBeDrawn[j], 0);
		}
	}	
}

void Scene::addPlayer(float x, float y, float size, float rotation, sf::RenderWindow * window, sf::Color color)
{
	player = new Player(sf::Vector2f(x, y), sf::Vector2f(size, size), rotation, color);
	shapesToBeDrawn.push_back(player);
	noOfPlayers = 1;
}

void Scene::clear()
{
	shapesToBeDrawn.clear();
	noOfPlayers = 0;
}

void Scene::save1()
{
	std::ofstream output_file("./Levels/Level1.txt");
	for (int i = 0; i < shapesToBeDrawn.size(); i++)
	{
		output_file << "Object";
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

	Level1 = shapesToBeDrawn;
	
}

void Scene::save2()
{
	std::ofstream output_file("./Levels/Level2.txt");
	for (int i = 0; i < shapesToBeDrawn.size(); i++)
	{
		output_file << "Object";
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
	Level2 = shapesToBeDrawn;
	
}

void Scene::save3()
{
	std::ofstream output_file("./Levels/Level3.txt");
	for (int i = 0; i < shapesToBeDrawn.size(); i++)
	{
		output_file << "Object";
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
	Level3 = shapesToBeDrawn;
	
}

void Scene::load1()
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

	while (!input_file.eof())
	{
		input_file >> type >> posX >> posY >> sizeX >> sizeY >> rot >> r >> g >> b;

		if (type == 1)
		{
			addDrawable(new Objects(sf::Vector2f(posX, posY), sf::Vector2f(sizeX, sizeY), rot, sf::Color(r, g, b), 0));
		}
		if (type == 2)
		{
			addDrawable(new Player(sf::Vector2f(posX, posY), sf::Vector2f(sizeX, sizeY), rot, sf::Color(r, g, b)));
		}
	}
	
}

void Scene::load2()
{
	
}

void Scene::load3()
{
	
}
