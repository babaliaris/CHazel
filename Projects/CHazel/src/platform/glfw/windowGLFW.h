#ifndef CHAZEL_WINDOW_GLFW_H
#define CHAZEL_WINDOW_GLFW_H

#include <GLFW/glfw3.h>
#include <core/window.h>

typedef struct CHazelWindowGLFW
{
	struct CHazelWindowGLFW* obj;

	GLFWwindow* m_Window;

	void (*__OnDestroy__)(struct CHazelWindowGLFW* obj);

}
CHazelWindowGLFW;

#endif