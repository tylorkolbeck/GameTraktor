#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace GameTraktor {
	class GT_API Log 
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}


// Core log macros
#define GT_CORE_TRACE(...)  ::GameTraktor::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GT_CORE_INFO(...)   ::GameTraktor::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GT_CORE_WARN(...)   ::GameTraktor::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GT_CORE_ERROR(...)  ::GameTraktor::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GT_CORE_FATAL(...)  ::GameTraktor::Log::GetCoreLogger()->fatal(__VA_ARGS__)



// Client log macros
#define GT_TRACE(...)       ::GameTraktor::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GT_INFO(...)        ::GameTraktor::Log::GetClientLogger()->info(__VA_ARGS__)
#define GT_WARN(...)        ::GameTraktor::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GT_ERROR(...)       ::GameTraktor::Log::GetClientLogger()->error(__VA_ARGS__)
#define GT_FATAL(...)       ::GameTraktor::Log::GetClientLogger()->fatal(__VA_ARGS__)
