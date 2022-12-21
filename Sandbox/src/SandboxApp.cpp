#include <GameTraktor.h>

class Sandbox : public GameTraktor::Application
{
public:
	Sandbox(){}
	~Sandbox(){}
};

GameTraktor::Application* GameTraktor::CreateApplication()
{
	return new Sandbox();
}

