workspace "GameTraktor"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-${cfg.architecture}"

project "GameTraktor"
	location "GameTraktor"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h"
		"%{prj.name}/src/**.cpp"
	}

	include
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"GT_PLATFORM_WINDOWS",
			"GT_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	filter "configurations:Debug"
		defines "GT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GT_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h"
		"%{prj.name}/src/**.cpp"
	}

	include
	{
		"%{prj.name}/vendor/spdlog/include",
		"GameTraktor/src"
	}

	links
	{
		"GameTraktor"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
	defines
	{
		"GT_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "GT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GT_DIST"
		optimize "On"


