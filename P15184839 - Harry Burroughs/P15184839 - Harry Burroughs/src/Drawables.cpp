#include "Drawables.h"

Drawables::Drawables(Scene* scene)
{
	this->scene = scene;
}

void Drawables::drawSquare(float x, float y, float size, sf::RenderWindow* window)
{
	sf::RectangleShape* Rectangle =  new sf::RectangleShape();
	Rectangle->setSize(sf::Vector2f(size, size));
	Rectangle->setOrigin(Rectangle->getSize().x / 2.0f, Rectangle->getSize().y / 2.0f);
	Rectangle->setPosition(x, y);
	Rectangle->setFillColor(sf::Color::Red);
	scene->addDrawable(Rectangle);
}
