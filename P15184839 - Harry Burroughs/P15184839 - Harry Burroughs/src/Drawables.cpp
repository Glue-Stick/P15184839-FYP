#include "Drawables.h"

static const float SCALE = 30.f; /*!< We need this to easily convert between pixel and real-world coordinates. */

Drawables::Drawables(Scene* scene)
{
	this->scene = scene;
	
}

void Drawables::drawRedSquare(float x, float y, float size, float rotation, sf::RenderWindow* window, sf::Color color, b2World world)
{
	sf::RectangleShape* Rectangle =  new sf::RectangleShape();
	Rectangle->setSize(sf::Vector2f(size, size));
	Rectangle->setOrigin(Rectangle->getSize().x / 2.0f, Rectangle->getSize().y / 2.0f);
	Rectangle->setPosition(x, y);
	Rectangle->setRotation(rotation);
	Rectangle->setFillColor(color);
	Rectangle->setOutlineColor(sf::Color::Black);
	Rectangle->setOutlineThickness(1.f);

	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(x / 30.f, y / 30.f); /*!< Creates the object at the x and y coordinates passed in when the object is called in the draw function */
	BodyDef.type = b2_dynamicBody;
	b2Body* Body3 = world.CreateBody(&BodyDef);
	Body3->SetUserData((void*)4); /*!< Sets the user data, which will be used when reseting the map and drawing the sprite to the object. */

	b2PolygonShape obstacle;
	obstacle.SetAsBox((50.f / 2) / 30.f, (50.f / 2) / 30.f); /*!< Creates a box shape, divided by the desired width and height. */
	b2FixtureDef FixtureDef;
	FixtureDef.density = 0.f; /*!< Sets the density of the body. */
	FixtureDef.shape = &obstacle; /*!< Sets the shape. */
	Body3->CreateFixture(&FixtureDef);

	scene->addDrawable(Rectangle);
}

void Drawables::drawBlueSquare(float x, float y, float size, float rotation, sf::RenderWindow * window, sf::Color color)
{
	sf::RectangleShape* Rectangle = new sf::RectangleShape();
	Rectangle->setSize(sf::Vector2f(size, size));
	Rectangle->setOrigin(Rectangle->getSize().x / 2.0f, Rectangle->getSize().y / 2.0f);
	Rectangle->setPosition(x, y);
	Rectangle->setRotation(rotation);
	Rectangle->setFillColor(color);
	Rectangle->setOutlineColor(sf::Color::Black);
	Rectangle->setOutlineThickness(1.f);

	scene->addDrawable(Rectangle);
}

void Drawables::drawYellowSquare(float x, float y, float size, float rotation, sf::RenderWindow * window, sf::Color color)
{
	sf::RectangleShape* Rectangle = new sf::RectangleShape();
	Rectangle->setSize(sf::Vector2f(size, size));
	Rectangle->setOrigin(Rectangle->getSize().x / 2.0f, Rectangle->getSize().y / 2.0f);
	Rectangle->setPosition(x, y);
	Rectangle->setRotation(rotation);
	Rectangle->setFillColor(color);
	Rectangle->setOutlineColor(sf::Color::Black);
	Rectangle->setOutlineThickness(1.f);

	scene->addDrawable(Rectangle);
}

void Drawables::drawPlayer(float x, float y, float size, float rotation, sf::RenderWindow * window, sf::Color color)
{
	sf::RectangleShape* Player = new sf::RectangleShape();
	Player->setSize(sf::Vector2f(size, size));
	Player->setOrigin(Player->getSize().x / 2.0f, Player->getSize().y / 2.0f);
	Player->setPosition(x, y);
	Player->setRotation(rotation);
	Player->setFillColor(color);
	Player->setOutlineColor(color);
	Player->setOutlineThickness(1.f);

	scene->addDrawable(Player);
}

void Drawables::drawGrid(float x, float y, sf::RenderWindow * window)
{
	/* Horizontal Lines */
	sf::RectangleShape* Horizontal1 = new sf::RectangleShape();
	Horizontal1->setSize(sf::Vector2f(1400.f, 1.f));
	Horizontal1->setOrigin(Horizontal1->getSize().x / 2.0f, Horizontal1->getSize().y / 2.0f);
	Horizontal1->setPosition(x, y);
	Horizontal1->setFillColor(sf::Color::Black);

	scene->addDrawable(Horizontal1);

	sf::RectangleShape* Horizontal2 = new sf::RectangleShape();
	Horizontal2->setSize(sf::Vector2f(1400.f, 1.f));
	Horizontal2->setOrigin(Horizontal2->getSize().x / 2.0f, Horizontal2->getSize().y / 2.0f);
	Horizontal2->setPosition(x, y + 50);
	Horizontal2->setFillColor(sf::Color::Black);

	scene->addDrawable(Horizontal2);

	sf::RectangleShape* Horizontal3 = new sf::RectangleShape();
	Horizontal3->setSize(sf::Vector2f(1400.f, 1.f));
	Horizontal3->setOrigin(Horizontal3->getSize().x / 2.0f, Horizontal3->getSize().y / 2.0f);
	Horizontal3->setPosition(x, y + 100);
	Horizontal3->setFillColor(sf::Color::Black);

	scene->addDrawable(Horizontal3);

	sf::RectangleShape* Horizontal4 = new sf::RectangleShape();
	Horizontal4->setSize(sf::Vector2f(1400.f, 1.f));
	Horizontal4->setOrigin(Horizontal4->getSize().x / 2.0f, Horizontal4->getSize().y / 2.0f);
	Horizontal4->setPosition(x, y + 150);
	Horizontal4->setFillColor(sf::Color::Black);

	scene->addDrawable(Horizontal4);

	sf::RectangleShape* Horizontal5 = new sf::RectangleShape();
	Horizontal5->setSize(sf::Vector2f(1400.f, 1.f));
	Horizontal5->setOrigin(Horizontal5->getSize().x / 2.0f, Horizontal5->getSize().y / 2.0f);
	Horizontal5->setPosition(x, y + 200);
	Horizontal5->setFillColor(sf::Color::Black);

	scene->addDrawable(Horizontal5);

	sf::RectangleShape* Horizontal6 = new sf::RectangleShape();
	Horizontal6->setSize(sf::Vector2f(1400.f, 1.f));
	Horizontal6->setOrigin(Horizontal6->getSize().x / 2.0f, Horizontal6->getSize().y / 2.0f);
	Horizontal6->setPosition(x, y + 250);
	Horizontal6->setFillColor(sf::Color::Black);

	scene->addDrawable(Horizontal6);

	sf::RectangleShape* Horizontal7 = new sf::RectangleShape();
	Horizontal7->setSize(sf::Vector2f(1400.f, 1.f));
	Horizontal7->setOrigin(Horizontal7->getSize().x / 2.0f, Horizontal7->getSize().y / 2.0f);
	Horizontal7->setPosition(x, y + 300);
	Horizontal7->setFillColor(sf::Color::Black);

	scene->addDrawable(Horizontal7);

	sf::RectangleShape* Horizontal8 = new sf::RectangleShape();
	Horizontal8->setSize(sf::Vector2f(1400.f, 1.f));
	Horizontal8->setOrigin(Horizontal8->getSize().x / 2.0f, Horizontal8->getSize().y / 2.0f);
	Horizontal8->setPosition(x, y + 350);
	Horizontal8->setFillColor(sf::Color::Black);

	scene->addDrawable(Horizontal8);

	sf::RectangleShape* Horizontal9 = new sf::RectangleShape();
	Horizontal9->setSize(sf::Vector2f(1400.f, 1.f));
	Horizontal9->setOrigin(Horizontal9->getSize().x / 2.0f, Horizontal9->getSize().y / 2.0f);
	Horizontal9->setPosition(x, y + 400);
	Horizontal9->setFillColor(sf::Color::Black);

	scene->addDrawable(Horizontal9);

	sf::RectangleShape* Horizontal10 = new sf::RectangleShape();
	Horizontal10->setSize(sf::Vector2f(1400.f, 1.f));
	Horizontal10->setOrigin(Horizontal10->getSize().x / 2.0f, Horizontal10->getSize().y / 2.0f);
	Horizontal10->setPosition(x, y - 50);
	Horizontal10->setFillColor(sf::Color::Black);

	scene->addDrawable(Horizontal10);

	sf::RectangleShape* Horizontal11 = new sf::RectangleShape();
	Horizontal11->setSize(sf::Vector2f(1400.f, 1.f));
	Horizontal11->setOrigin(Horizontal11->getSize().x / 2.0f, Horizontal11->getSize().y / 2.0f);
	Horizontal11->setPosition(x, y - 100);
	Horizontal11->setFillColor(sf::Color::Black);

	scene->addDrawable(Horizontal11);

	sf::RectangleShape* Horizontal12 = new sf::RectangleShape();
	Horizontal12->setSize(sf::Vector2f(1400.f, 1.f));
	Horizontal12->setOrigin(Horizontal12->getSize().x / 2.0f, Horizontal12->getSize().y / 2.0f);
	Horizontal12->setPosition(x, y - 150);
	Horizontal12->setFillColor(sf::Color::Black);

	scene->addDrawable(Horizontal12);

	sf::RectangleShape* Horizontal13 = new sf::RectangleShape();
	Horizontal13->setSize(sf::Vector2f(1400.f, 1.f));
	Horizontal13->setOrigin(Horizontal13->getSize().x / 2.0f, Horizontal13->getSize().y / 2.0f);
	Horizontal13->setPosition(x, y - 200);
	Horizontal13->setFillColor(sf::Color::Black);

	scene->addDrawable(Horizontal13);

	sf::RectangleShape* Horizontal14 = new sf::RectangleShape();
	Horizontal14->setSize(sf::Vector2f(1400.f, 1.f));
	Horizontal14->setOrigin(Horizontal14->getSize().x / 2.0f, Horizontal14->getSize().y / 2.0f);
	Horizontal14->setPosition(x, y - 250);
	Horizontal14->setFillColor(sf::Color::Black);

	scene->addDrawable(Horizontal14);

	sf::RectangleShape* Horizontal15 = new sf::RectangleShape();
	Horizontal15->setSize(sf::Vector2f(1400.f, 1.f));
	Horizontal15->setOrigin(Horizontal15->getSize().x / 2.0f, Horizontal15->getSize().y / 2.0f);
	Horizontal15->setPosition(x, y - 300);
	Horizontal15->setFillColor(sf::Color::Black);

	scene->addDrawable(Horizontal15);

	sf::RectangleShape* Horizontal16 = new sf::RectangleShape();
	Horizontal16->setSize(sf::Vector2f(1400.f, 1.f));
	Horizontal16->setOrigin(Horizontal16->getSize().x / 2.0f, Horizontal16->getSize().y / 2.0f);
	Horizontal16->setPosition(x, y - 350);
	Horizontal16->setFillColor(sf::Color::Black);

	scene->addDrawable(Horizontal16);

	sf::RectangleShape* Horizontal17 = new sf::RectangleShape();
	Horizontal17->setSize(sf::Vector2f(1400.f, 1.f));
	Horizontal17->setOrigin(Horizontal17->getSize().x / 2.0f, Horizontal17->getSize().y / 2.0f);
	Horizontal17->setPosition(x, y - 400);
	Horizontal17->setFillColor(sf::Color::Black);

	scene->addDrawable(Horizontal17);

	sf::RectangleShape* Horizontal18 = new sf::RectangleShape();
	Horizontal18->setSize(sf::Vector2f(1400.f, 1.f));
	Horizontal18->setOrigin(Horizontal18->getSize().x / 2.0f, Horizontal18->getSize().y / 2.0f);
	Horizontal18->setPosition(x, y - 450);
	Horizontal18->setFillColor(sf::Color::Black);

	scene->addDrawable(Horizontal18);

	/* Vertical Lines */

	sf::RectangleShape* Vertical1 = new sf::RectangleShape();
	Vertical1->setSize(sf::Vector2f(1.f, 900.f));
	Vertical1->setOrigin(Vertical1->getSize().x / 2.0f, Vertical1->getSize().y / 2.0f);
	Vertical1->setPosition(x, y);
	Vertical1->setFillColor(sf::Color::Black);

	scene->addDrawable(Vertical1);

	sf::RectangleShape* Vertical2 = new sf::RectangleShape();
	Vertical2->setSize(sf::Vector2f(1.f, 900.f));
	Vertical2->setOrigin(Vertical2->getSize().x / 2.0f, Vertical2->getSize().y / 2.0f);
	Vertical2->setPosition(x + 100, y);
	Vertical2->setFillColor(sf::Color::Black);

	scene->addDrawable(Vertical2);

	sf::RectangleShape* Vertical3 = new sf::RectangleShape();
	Vertical3->setSize(sf::Vector2f(1.f, 900.f));
	Vertical3->setOrigin(Vertical3->getSize().x / 2.0f, Vertical3->getSize().y / 2.0f);
	Vertical3->setPosition(x + 200, y);
	Vertical3->setFillColor(sf::Color::Black);

	scene->addDrawable(Vertical3);

	sf::RectangleShape* Vertical4 = new sf::RectangleShape();
	Vertical4->setSize(sf::Vector2f(1.f, 900.f));
	Vertical4->setOrigin(Vertical4->getSize().x / 2.0f, Vertical4->getSize().y / 2.0f);
	Vertical4->setPosition(x + 300, y);
	Vertical4->setFillColor(sf::Color::Black);

	scene->addDrawable(Vertical4);

	sf::RectangleShape* Vertical5 = new sf::RectangleShape();
	Vertical5->setSize(sf::Vector2f(1.f, 900.f));
	Vertical5->setOrigin(Vertical5->getSize().x / 2.0f, Vertical5->getSize().y / 2.0f);
	Vertical5->setPosition(x + 400, y);
	Vertical5->setFillColor(sf::Color::Black);

	scene->addDrawable(Vertical5);

	sf::RectangleShape* Vertical6 = new sf::RectangleShape();
	Vertical6->setSize(sf::Vector2f(1.f, 900.f));
	Vertical6->setOrigin(Vertical6->getSize().x / 2.0f, Vertical6->getSize().y / 2.0f);
	Vertical6->setPosition(x + 500, y);
	Vertical6->setFillColor(sf::Color::Black);

	scene->addDrawable(Vertical6);

	sf::RectangleShape* Vertical7 = new sf::RectangleShape();
	Vertical7->setSize(sf::Vector2f(1.f, 900.f));
	Vertical7->setOrigin(Vertical7->getSize().x / 2.0f, Vertical7->getSize().y / 2.0f);
	Vertical7->setPosition(x + 600, y);
	Vertical7->setFillColor(sf::Color::Black);

	scene->addDrawable(Vertical7);

	sf::RectangleShape* Vertical8 = new sf::RectangleShape();
	Vertical8->setSize(sf::Vector2f(1.f, 900.f));
	Vertical8->setOrigin(Vertical8->getSize().x / 2.0f, Vertical8->getSize().y / 2.0f);
	Vertical8->setPosition(x + 700, y);
	Vertical8->setFillColor(sf::Color::Black);

	scene->addDrawable(Vertical8);

	sf::RectangleShape* Vertical9 = new sf::RectangleShape();
	Vertical9->setSize(sf::Vector2f(1.f, 900.f));
	Vertical9->setOrigin(Vertical9->getSize().x / 2.0f, Vertical9->getSize().y / 2.0f);
	Vertical9->setPosition(x -100, y);
	Vertical9->setFillColor(sf::Color::Black);

	scene->addDrawable(Vertical9);

	sf::RectangleShape* Vertical10 = new sf::RectangleShape();
	Vertical10->setSize(sf::Vector2f(1.f, 900.f));
	Vertical10->setOrigin(Vertical10->getSize().x / 2.0f, Vertical10->getSize().y / 2.0f);
	Vertical10->setPosition(x - 200, y);
	Vertical10->setFillColor(sf::Color::Black);

	scene->addDrawable(Vertical10);

	sf::RectangleShape* Vertical11 = new sf::RectangleShape();
	Vertical11->setSize(sf::Vector2f(1.f, 900.f));
	Vertical11->setOrigin(Vertical11->getSize().x / 2.0f, Vertical11->getSize().y / 2.0f);
	Vertical11->setPosition(x - 300, y);
	Vertical11->setFillColor(sf::Color::Black);

	scene->addDrawable(Vertical11);

	sf::RectangleShape* Vertical12 = new sf::RectangleShape();
	Vertical12->setSize(sf::Vector2f(1.f, 900.f));
	Vertical12->setOrigin(Vertical12->getSize().x / 2.0f, Vertical12->getSize().y / 2.0f);
	Vertical12->setPosition(x - 400, y);
	Vertical12->setFillColor(sf::Color::Black);

	scene->addDrawable(Vertical12);

	sf::RectangleShape* Vertical13 = new sf::RectangleShape();
	Vertical13->setSize(sf::Vector2f(1.f, 900.f));
	Vertical13->setOrigin(Vertical13->getSize().x / 2.0f, Vertical13->getSize().y / 2.0f);
	Vertical13->setPosition(x - 500, y);
	Vertical13->setFillColor(sf::Color::Black);

	scene->addDrawable(Vertical13);

	sf::RectangleShape* Vertical14 = new sf::RectangleShape();
	Vertical14->setSize(sf::Vector2f(1.f, 900.f));
	Vertical14->setOrigin(Vertical14->getSize().x / 2.0f, Vertical14->getSize().y / 2.0f);
	Vertical14->setPosition(x - 600, y);
	Vertical14->setFillColor(sf::Color::Black);

	scene->addDrawable(Vertical14);

	sf::RectangleShape* Vertical15 = new sf::RectangleShape();
	Vertical15->setSize(sf::Vector2f(1.f, 900.f));
	Vertical15->setOrigin(Vertical15->getSize().x / 2.0f, Vertical15->getSize().y / 2.0f);
	Vertical15->setPosition(x - 700, y);
	Vertical15->setFillColor(sf::Color::Black);

	scene->addDrawable(Vertical15);
}

void Drawables::drawGridNumbers(float x, float y, sf::RenderWindow * window)
{
	/*!< Prepare the fonts to print to screen. */
	if (!Font.loadFromFile("C:/Windows/Fonts/arial.ttf"))
	{
		/*!< If the font cannot be found from the file an exception will be thrown. */
		std::cout << "Error" << std::endl;
	}


	/* Horizontal Numbers*/

	sf::Text* Htext = new sf::Text();
	Htext->setFont(Font);
	Htext->setString("1300");
	Htext->setCharacterSize(14);
	Htext->setFillColor(sf::Color::Black);
	Htext->setStyle(sf::Text::Bold);
	Htext->setPosition(1300, 10);

	scene->addText(Htext);

	sf::Text* Htext1 = new sf::Text();
	Htext1->setFont(Font);
	Htext1->setString("1200");
	Htext1->setCharacterSize(14);
	Htext1->setFillColor(sf::Color::Black);
	Htext1->setStyle(sf::Text::Bold);
	Htext1->setPosition(1200, 10);

	scene->addText(Htext1);

	sf::Text* Htext2 = new sf::Text();
	Htext2->setFont(Font);
	Htext2->setString("1100");
	Htext2->setCharacterSize(14);
	Htext2->setFillColor(sf::Color::Black);
	Htext2->setStyle(sf::Text::Bold);
	Htext2->setPosition(1100, 10);

	scene->addText(Htext2);

	sf::Text* Htext3 = new sf::Text();
	Htext3->setFont(Font);
	Htext3->setString("1000");
	Htext3->setCharacterSize(14);
	Htext3->setFillColor(sf::Color::Black);
	Htext3->setStyle(sf::Text::Bold);
	Htext3->setPosition(1000, 10);

	scene->addText(Htext3);

	sf::Text* Htext4 = new sf::Text();
	Htext4->setFont(Font);
	Htext4->setString("900");
	Htext4->setCharacterSize(14);
	Htext4->setFillColor(sf::Color::Black);
	Htext4->setStyle(sf::Text::Bold);
	Htext4->setPosition(900, 10);

	scene->addText(Htext4);

	sf::Text* Htext5 = new sf::Text();
	Htext5->setFont(Font);
	Htext5->setString("800");
	Htext5->setCharacterSize(14);
	Htext5->setFillColor(sf::Color::Black);
	Htext5->setStyle(sf::Text::Bold);
	Htext5->setPosition(800, 10);

	scene->addText(Htext5);

	sf::Text* Htext6 = new sf::Text();
	Htext6->setFont(Font);
	Htext6->setString("700");
	Htext6->setCharacterSize(14);
	Htext6->setFillColor(sf::Color::Black);
	Htext6->setStyle(sf::Text::Bold);
	Htext6->setPosition(700, 10);

	scene->addText(Htext6);

	sf::Text* Htext7 = new sf::Text();
	Htext7->setFont(Font);
	Htext7->setString("600");
	Htext7->setCharacterSize(14);
	Htext7->setFillColor(sf::Color::Black);
	Htext7->setStyle(sf::Text::Bold);
	Htext7->setPosition(600, 10);

	scene->addText(Htext7);

	sf::Text* Htext8 = new sf::Text();
	Htext8->setFont(Font);
	Htext8->setString("500");
	Htext8->setCharacterSize(14);
	Htext8->setFillColor(sf::Color::Black);
	Htext8->setStyle(sf::Text::Bold);
	Htext8->setPosition(500, 10);

	scene->addText(Htext8);

	sf::Text* Htext9 = new sf::Text();
	Htext9->setFont(Font);
	Htext9->setString("400");
	Htext9->setCharacterSize(14);
	Htext9->setFillColor(sf::Color::Black);
	Htext9->setStyle(sf::Text::Bold);
	Htext9->setPosition(400, 10);

	scene->addText(Htext9);

	sf::Text* Htext10 = new sf::Text();
	Htext10->setFont(Font);
	Htext10->setString("300");
	Htext10->setCharacterSize(14);
	Htext10->setFillColor(sf::Color::Black);
	Htext10->setStyle(sf::Text::Bold);
	Htext10->setPosition(300, 10);

	scene->addText(Htext10);

	sf::Text* Htext11 = new sf::Text();
	Htext11->setFont(Font);
	Htext11->setString("200");
	Htext11->setCharacterSize(14);
	Htext11->setFillColor(sf::Color::Black);
	Htext11->setStyle(sf::Text::Bold);
	Htext11->setPosition(200, 10);

	scene->addText(Htext11);

	sf::Text* Htext12 = new sf::Text();
	Htext12->setFont(Font);
	Htext12->setString("100");
	Htext12->setCharacterSize(14);
	Htext12->setFillColor(sf::Color::Black);
	Htext12->setStyle(sf::Text::Bold);
	Htext12->setPosition(100, 10);

	scene->addText(Htext12);

	sf::Text* Htext13 = new sf::Text();
	Htext13->setFont(Font);
	Htext13->setString("0");
	Htext13->setCharacterSize(14);
	Htext13->setFillColor(sf::Color::Black);
	Htext13->setStyle(sf::Text::Bold);
	Htext13->setPosition(0, 10);

	scene->addText(Htext13);

	/* Vertical Numbers */
	
	sf::Text* Vtext1 = new sf::Text();
	Vtext1->setFont(Font);
	Vtext1->setString("100");
	Vtext1->setCharacterSize(14);
	Vtext1->setFillColor(sf::Color::Black);
	Vtext1->setStyle(sf::Text::Bold);
	Vtext1->setPosition(1350, 100);

	scene->addText(Vtext1);

	sf::Text* Vtext2 = new sf::Text();
	Vtext2->setFont(Font);
	Vtext2->setString("200");
	Vtext2->setCharacterSize(14);
	Vtext2->setFillColor(sf::Color::Black);
	Vtext2->setStyle(sf::Text::Bold);
	Vtext2->setPosition(1350, 200);

	scene->addText(Vtext2);

	sf::Text* Vtext3 = new sf::Text();
	Vtext3->setFont(Font);
	Vtext3->setString("300");
	Vtext3->setCharacterSize(14);
	Vtext3->setFillColor(sf::Color::Black);
	Vtext3->setStyle(sf::Text::Bold);
	Vtext3->setPosition(1350, 300);

	scene->addText(Vtext3);

	sf::Text* Vtext4 = new sf::Text();
	Vtext4->setFont(Font);
	Vtext4->setString("400");
	Vtext4->setCharacterSize(14);
	Vtext4->setFillColor(sf::Color::Black);
	Vtext4->setStyle(sf::Text::Bold);
	Vtext4->setPosition(1350, 400);

	scene->addText(Vtext4);

	sf::Text* Vtext5 = new sf::Text();
	Vtext5->setFont(Font);
	Vtext5->setString("500");
	Vtext5->setCharacterSize(14);
	Vtext5->setFillColor(sf::Color::Black);
	Vtext5->setStyle(sf::Text::Bold);
	Vtext5->setPosition(1350, 500);

	scene->addText(Vtext5);

	sf::Text* Vtext6 = new sf::Text();
	Vtext6->setFont(Font);
	Vtext6->setString("600");
	Vtext6->setCharacterSize(14);
	Vtext6->setFillColor(sf::Color::Black);
	Vtext6->setStyle(sf::Text::Bold);
	Vtext6->setPosition(1350, 600);

	scene->addText(Vtext6);

	sf::Text* Vtext7 = new sf::Text();
	Vtext7->setFont(Font);
	Vtext7->setString("700");
	Vtext7->setCharacterSize(14);
	Vtext7->setFillColor(sf::Color::Black);
	Vtext7->setStyle(sf::Text::Bold);
	Vtext7->setPosition(1350, 700);

	scene->addText(Vtext7);
	
	sf::Text* Vtext8 = new sf::Text();
	Vtext8->setFont(Font);
	Vtext8->setString("800");
	Vtext8->setCharacterSize(14);
	Vtext8->setFillColor(sf::Color::Black);
	Vtext8->setStyle(sf::Text::Bold);
	Vtext8->setPosition(1350, 800);

	scene->addText(Vtext8);
}
