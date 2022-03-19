#include "pch.h"
#include "windowGLFW.h"
#include <core/core.h>


static void OnCHazelWindowDestroy(CHazelWindow* obj)
{
	printf("...........................OnCHazelWindowDestroy()\n");
	CHazelWindowGLFW *windowGLFW = (CHazelWindowGLFW *)obj->obj;
	CHZ_DESTROY(windowGLFW);
}




static void OnDestroy(CHazelWindowGLFW* obj)
{
	printf("...........................WindowGLFW->OnDestroy()\n");
	glfwDestroyWindow(obj->m_Window);
	glfwTerminate();
}




static int GetWidth(CHazelWindowGLFW* obj)
{
	int width, height;
	glfwGetWindowSize(obj->m_Window, &width, &height);
	return width;
}




static int GetHeight(CHazelWindowGLFW* obj)
{
	int width, height;
	glfwGetWindowSize(obj->m_Window, &width, &height);
	return height;
}




static void* GetNativeWindow(CHazelWindowGLFW* obj)
{
	return (void *)obj->m_Window;
}




static void Update(CHazelWindowGLFW* obj)
{
	glfwPollEvents();
	glfwSwapBuffers(obj->m_Window);
}




CHazelWindow* CHazelCreateWindow(const char *title, int width, int height)
{
	if (!glfwInit())
	{
		printf("GLFW failed to initialize.\n");
		return NULL;
	}

	GLFWwindow* glfw_window = glfwCreateWindow(width, height, title, NULL, NULL);

	if (glfw_window == NULL)
	{
		printf("GLFW failed to create a window.\n");
		return NULL;
	}

	glfwMakeContextCurrent(glfw_window);

	//Create the window.
	CHazelWindow* new_window = (CHazelWindow *)CHZ_NEW(CHazelWindow);

	//Create the CHazelWindowGLFW
	CHazelWindowGLFW *new_WindowGLFW = (CHazelWindowGLFW *)CHZ_NEW(CHazelWindowGLFW);

	//Initialize the CHazelWindow.
	new_window->obj 			= new_WindowGLFW;
	new_window->__OnDestroy__	= OnCHazelWindowDestroy;
	new_window->GetWidth 		= GetWidth;
	new_window->GetHeight 		= GetHeight;
	new_window->GetNativeWindow = GetNativeWindow;
	new_window->Update 			= Update;


	//Initialize the CHazelWindowGLFW.
	new_WindowGLFW->obj 			= new_WindowGLFW;
	new_WindowGLFW->__OnDestroy__ 	= OnDestroy;
	new_WindowGLFW->m_Window 		= glfw_window;

	return new_window;
}