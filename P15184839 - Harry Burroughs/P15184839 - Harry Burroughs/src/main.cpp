#include <iostream>
#include <GameApp.h>
#include <Drawables.h>

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
	//glClearColor(255.0f, 255.0f, 255.0f, 1.0f);
	return true;
}

void TestApp::Update(sf::Time & time)
{
	
	//std::cout << "1" << std::endl;
}

void TestApp::Render(sf::Time & time)
{
	//glClear(GL_COLOR_BUFFER_BIT);
	//draw.drawSquare(700, 450);
}

void TestApp::Cleanup()
{

}
