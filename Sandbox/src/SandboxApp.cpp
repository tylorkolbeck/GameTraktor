#include <GameTraktor.h>

class ExampleLayer : public GameTraktor::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{}

	void OnUpdate() override
	{
		if (GameTraktor::Input::IsKeyPressed(GT_KEY_TAB))
			GT_TRACE("TAB KEY PRESSED");
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

