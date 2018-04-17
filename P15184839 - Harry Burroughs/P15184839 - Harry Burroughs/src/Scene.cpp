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
	if (player != nullptr)
	{
		window->draw(*player->getDrawable());
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
			shapesToBeDrawn[j]->checkCollision(*player, 0);
			player->checkCollision(*shapesToBeDrawn[j], 0);
		}
	}	
}

void Scene::addPlayer(float x, float y, float size, float rotation, sf::RenderWindow * window, sf::Color color)
{
	player = new Player(sf::Vector2f(x, y), sf::Vector2f(size, size), color);
}

void Scene::clear()
{
	shapesToBeDrawn.clear();
	player = nullptr;
}

void Scene::save1()
{
	Level1 = shapesToBeDrawn;
	clear();
}

void Scene::save2()
{
	Level2 = shapesToBeDrawn;
	clear();
}

void Scene::save3()
{
	Level3 = shapesToBeDrawn;
	clear();
}

void Scene::load1()
{
	shapesToBeDrawn = Level1;
}

void Scene::load2()
{
	shapesToBeDrawn = Level2;
}

void Scene::load3()
{
	shapesToBeDrawn = Level3;
}
