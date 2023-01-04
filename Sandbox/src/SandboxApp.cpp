#include <GameTraktor.h>

class ExampleLayer : public GameTraktor::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{}

	void OnUpdate() override
	{

	}

	void OnEvent(GameTraktor::Event& event) override
	{

	}
};

class Sandbox : public GameTraktor::Application
{
public:
	Sandbox(){
		PushLayer(new ExampleLayer());
		PushOverlay(new GameTraktor::ImGuiLayer());

	}
	~Sandbox(){}
};

GameTraktor::Application* GameTraktor::CreateApplication()
{
	return new Sandbox();
}

