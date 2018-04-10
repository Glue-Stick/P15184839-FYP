#include "Drawables.h"

void Drawables::drawSquare(float x, float y, float size, sf::RenderWindow* window)
{
	sf::RectangleShape Rectangle;
	Rectangle.setSize(sf::Vector2f(size, size));
	Rectangle.setOrigin(Rectangle.getSize().x / 2.0f, Rectangle.getSize().y / 2.0f);
	Rectangle.setPosition(x, y);
	Rectangle.setFillColor(sf::Color::Red);
	window->draw(Rectangle);
}
