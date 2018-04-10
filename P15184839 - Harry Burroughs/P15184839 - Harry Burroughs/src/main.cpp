#include <iostream>
#include <GameApp.h>
#include <Drawables.h>

Drawables draw;

class TestApp : public GameApp
{
public:
	TestApp();
	TestApp(const TestApp& other);
	TestApp& operator=(const TestApp&);
	~TestApp();

	//framework overloads
	bool Init() override;
	void Update(sf::Time& time) override;
	void Render(sf::Time& time) override;
	void Cleanup() override;
};


int main()
{
	TestApp tApp;

	tApp.Run();

	return 0;
}

TestApp::TestApp()
{

}

TestApp::~TestApp()
{
}

bool TestApp::Init()
{
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	draw.drawSquare(400, 300);
	return true;
}

void TestApp::Update(sf::Time & time)
{
	std::cout << "1" << std::endl;
}

void TestApp::Render(sf::Time & time)
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void TestApp::Cleanup()
{

}
