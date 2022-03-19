project "CHazel"
	kind "StaticLib"
	language "C"
	targetdir "%{_WORKING_DIR}/builds/%{cfg.shortname}/"
	objdir "%{_WORKING_DIR}/obj/%{prj.name}_%{cfg.shortname}/"

	pchheader "pch.h"
	pchsource "src/pch.c"

	files{
		"src/**.h",
		"src/**.c"
	}

	includedirs{
		"src/",
		"%{_WORKING_DIR}/External/glfw/include/",
		"%{_WORKING_DIR}/Projects/Glad/include/"
	}

	filter{}
	filter "system:linux"
		buildoptions {"-Wno-incompatible-pointer-types"}