#pragma once
#include "Core.h"

namespace GameTraktor {
	class GT_API Application 
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}

