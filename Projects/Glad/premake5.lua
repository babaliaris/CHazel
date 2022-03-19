project "Glad"
	kind "StaticLib"
	language "C"
	targetdir "%{_WORKING_DIR}/builds/%{cfg.shortname}/"
	objdir "%{_WORKING_DIR}/obj/%{prj.name}_%{cfg.shortname}/"

	files{
		"src/**.h",
		"include/**.h",
		"src/**.c"
	}

	includedirs{
		"include/"
	}