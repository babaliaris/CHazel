project "Sandbox"
	kind "ConsoleApp"
	language "C"
	targetdir "%{_WORKING_DIR}/builds/%{cfg.shortname}/"
	objdir "%{_WORKING_DIR}/obj/%{prj.name}_%{cfg.shortname}/"

	files{
		"src/**.h",
		"src/**.c"
	}

	includedirs{
		"src/",
		"../CHazel/src/"
	}

	links{
		"CHazel",
		"GLFW",
		"Glad"
	}

	libdirs{
		"%{_WORKING_DIR}/builds/%{cfg.shortname}/"
	}

	filter{}
	filter "system:linux"
		links {"GL", "m", "X11", "pthread", "Xi", "Xrandr", "dl"}