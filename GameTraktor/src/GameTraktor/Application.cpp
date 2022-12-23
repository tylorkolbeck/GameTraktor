#include "gtpch.h"
#include "Application.h"

#include "GameTraktor/Events/ApplicationEvent.h"

namespace GameTraktor {
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}
	Application::~Application() {}

	void Application::OnEvent(Event& e)
	{

		GT_CORE_TRACE("{0}", e);
	}


	void Application::Run() 
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}