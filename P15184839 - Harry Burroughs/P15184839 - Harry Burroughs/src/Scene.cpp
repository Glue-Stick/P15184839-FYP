#include "Scene.h"

Scene::Scene()
{

}

void Scene::addDrawable(sf::Drawable* shape)
{
	toBeDrawn.push_back(shape);
}

void Scene::render(sf::RenderWindow* window)
{
	for (unsigned int i = 0; i < toBeDrawn.size(); i++)
	{
		window->draw(*toBeDrawn[i]);
	}
}
