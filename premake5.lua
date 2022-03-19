workspace "CHazel"
	configurations {"Debug", "PreRelease", "Release"}
	platforms {"x64"}
	startproject "Sandbox"

	filter "configurations:Debug"
		defines {"CHZ_DEBUG"}
		symbols "on"

	filter "configurations:PreRelease"
		defines {"CHZ_PRERELEASE"}
		optimize "on"

	filter "configurations:Release"
		defines {"CHZ_RELEASE"}
		optimize "on"

	group "External"
		include "External/glfw/"
		include "Projects/Glad/"
	group ""

	include "Projects/CHazel/"
	include "Projects/Sandbox/"