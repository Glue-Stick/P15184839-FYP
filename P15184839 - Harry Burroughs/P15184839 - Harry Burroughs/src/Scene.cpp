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

void Scene::save()
{
	Level1 = shapesToBeDrawn;
}

void Scene::load()
{
	shapesToBeDrawn = Level1;
}
