workspace "CHazel"
	configurations {"Debug", "PreRelease", "Release"}
	platforms {"x64"}
	startproject "Sandbox"

	filter{}
	filter "configurations:Debug"
		defines {"CHZ_DEBUG"}
		symbols "on"

	filter{}
	filter "configurations:PreRelease"
		defines {"CHZ_PRERELEASE"}
		optimize "on"

	filter{}
	filter "configurations:Release"
		defines {"CHZ_RELEASE"}
		optimize "on"


	filter{}
	filter "system:windows"
		defines {"CHZ_WINDOW"}

	filter{}
	filter "system:linux"
		defines {"CHZ_LINUX"}
	filter{}

	group "External"
		include "External/glfw/"
		include "Projects/Glad/"
	group ""

	include "Projects/CHazel/"
	include "Projects/Sandbox/"