#include "Drawables.h"

Drawables::Drawables(Scene* scene)
{
	this->scene = scene;
}

void Drawables::drawRedSquare(float x, float y, float size, sf::RenderWindow* window)
{
	sf::RectangleShape* Rectangle =  new sf::RectangleShape();
	Rectangle->setSize(sf::Vector2f(size, size));
	Rectangle->setOrigin(Rectangle->getSize().x / 2.0f, Rectangle->getSize().y / 2.0f);
	Rectangle->setPosition(x, y);
	//Rectangle->setOutlineColor(sf::Color::Black);
	Rectangle->setFillColor(sf::Color::Red);	

	scene->addDrawable(Rectangle);
}

void Drawables::drawBlueSquare(float x, float y, float size, sf::RenderWindow * window)
{
	sf::RectangleShape* Rectangle = new sf::RectangleShape();
	Rectangle->setSize(sf::Vector2f(size, size));
	Rectangle->setOrigin(Rectangle->getSize().x / 2.0f, Rectangle->getSize().y / 2.0f);
	Rectangle->setPosition(x, y);
	//Rectangle->setOutlineColor(sf::Color::Black);
	Rectangle->setFillColor(sf::Color::Blue);

	scene->addDrawable(Rectangle);
}

void Drawables::drawYellowSquare(float x, float y, float size, sf::RenderWindow * window)
{
	sf::RectangleShape* Rectangle = new sf::RectangleShape();
	Rectangle->setSize(sf::Vector2f(size, size));
	Rectangle->setOrigin(Rectangle->getSize().x / 2.0f, Rectangle->getSize().y / 2.0f);
	Rectangle->setPosition(x, y);
	//Rectangle->setOutlineColor(sf::Color::Black);
	Rectangle->setFillColor(sf::Color::Yellow);

	scene->addDrawable(Rectangle);
}
