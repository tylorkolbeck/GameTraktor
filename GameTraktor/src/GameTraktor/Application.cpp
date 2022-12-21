#include "gtpch.h"
#include "Application.h"
#include "GameTraktor/Events/ApplicationEvent.h"
#include "GameTraktor/Log.h"

namespace GameTraktor {
	Application::Application() {}
	Application::~Application() {}

	void Application::Run() 
	{
		WindowResizedEvent e(1280, 720);
		GT_TRACE(e);
		while (true);
	}
}  