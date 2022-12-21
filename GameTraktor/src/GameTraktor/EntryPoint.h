#pragma once

#ifdef GT_PLATFORM_WINDOWS

extern GameTraktor::Application* GameTraktor::CreateApplication();

int main(int argc, char** argv)
{
	GameTraktor::Log::Init();
	GT_CORE_WARN("Initialized Log");
	int a = 5;
	GT_INFO("Initialized Client Log Var={0}", a);

	auto app = GameTraktor::CreateApplication();
	
	app->Run();
	delete app;
}
#endif
