#pragma once

#ifdef GT_PLATFORM_WINDOWS

extern GameTraktor::Application* GameTraktor::CreateApplication();

int main(int argc, char** argv)
{
	auto app = GameTraktor::CreateApplication();
	
	app->Run();
	delete app;
}
#endif
