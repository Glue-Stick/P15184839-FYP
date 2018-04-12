#include "Scene.h"

Scene::Scene()
{

}

void Scene::addDrawable(sf::Drawable* shape)
{
	shapesToBeDrawn.push_back(shape);
}

void Scene::addText(sf::Text* text)
{
	gridToBeDrawn.push_back(text);
}

void Scene::render(sf::RenderWindow* window)
{
	for (unsigned int i = 0; i < shapesToBeDrawn.size(); i++)
	{
		window->draw(*shapesToBeDrawn[i]);
	}
	for (unsigned int i = 0; i < gridToBeDrawn.size(); i++)
	{
		window->draw(*gridToBeDrawn[i]);
	}
}

void Scene::clear()
{
	shapesToBeDrawn.clear();
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
