#include "Drawables.h"

void Drawables::drawSquare(float x, float y)
{
	sf::RectangleShape Rectangle;
	Rectangle.setSize(sf::Vector2f(20.f, 20.f));
	Rectangle.setOrigin(Rectangle.getSize().x / 2.0f, Rectangle.getSize().y / 2.0f);
	Rectangle.setPosition(x, y);
	Rectangle.setFillColor(sf::Color::Black);
	gameapp->m_window->draw(Rectangle);
}
