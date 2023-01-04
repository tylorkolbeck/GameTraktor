#pragma once

#ifdef GT_PLATFORM_WINDOWS
	#ifdef GT_BUILD_DLL
		#define GT_API __declspec(dllexport)
	#else
		#define GT_API __declspec(dllimport)
	#endif
#else
	#error Game Traktor only support Windows	
#endif

#ifdef GT_ENABLE_ASSERTS
	#define GT_ASSERT(x, ...) { if(!(x)) {GT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define GT_CORE_ASSERT(x, ...) { if(!x)) { GT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define GT_ASSERT(x, ...)
	#define GT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define GT_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
