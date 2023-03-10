#pragma once
#include "Core.h"

#include "Window.h"
#include "GameTraktor/LayerStack.h"
#include "Events/Event.h"
#include "GameTraktor/Events/ApplicationEvent.h"

namespace GameTraktor {
	class GT_API Application 
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
	};

	// To be defined in client
	Application* CreateApplication();
}

