#pragma once

#include "GameTraktor/Layer.h"

#include "GameTraktor/Events/KeyEvent.h"
#include "GameTraktor/Events/MouseEvent.h"
#include "GameTraktor/Events/ApplicationEvent.h"

namespace GameTraktor {

	class GT_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttatch();
		void OnDetatch();
		void OnUpdate();
		void OnEvent(Event& event);

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleased& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizedEvent(WindowResizedEvent& e);

	private:
		float m_Time = 0.0f;
	};
}