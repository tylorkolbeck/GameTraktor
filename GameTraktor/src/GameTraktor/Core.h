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
