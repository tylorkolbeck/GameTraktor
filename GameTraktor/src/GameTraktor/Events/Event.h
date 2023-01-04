#pragma once
#include "gtpch.h"

#include "GameTraktor/Core.h"


namespace GameTraktor {
	// Events are blocking, when an event is dispatched it immediatly gets
	// dispatched and is worked through at that time. 
	// TODO: A better strategy would be to 
	// buffer the events in an event bus and process them during the event period of the update stage 
	// (MultiThreaded Event System https://stackoverflow.com/questions/20689502/multithreaded-event-system)

	enum class EventType
	{
		None = 0,
		// Window Events
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		// App Events
		AppTick, AppUpdate, AppRender, 
		// Key Events
		KeyPressed, KeyReleased, KeyTyped,
		// Mouse Events
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type;  }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

	class GT_API Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }


		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

		bool IsHandled()
		{
			return m_Handled;
		}
	protected:
		bool m_Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			:m_Event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}
