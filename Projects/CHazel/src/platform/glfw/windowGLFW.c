#include "pch.h"
#include "windowGLFW.h"
#include <core/core.h>
#include <core/debug/coreLogger.h>


static void OnCHazelWindowDestroy(CHazelWindow* obj)
{
	CHazelWindowGLFW *windowGLFW = (CHazelWindowGLFW *)obj->obj;
	CHZ_DESTROY(windowGLFW);
}




static void OnDestroy(CHazelWindowGLFW* obj)
{
	CHZ_CORE_IMPORTANT("...........................WindowGLFW->OnDestroy()");
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
	//Initialize GLFW.
	int glfwSuccess = 0;
	CHZ_CORE_ASSERT_EQ(glfwSuccess = glfwInit(), 1, "GLFW failed to initialize.\n");
	if (!glfwSuccess) return NULL;

	//Create the Window.
	GLFWwindow* glfw_window = glfwCreateWindow(width, height, title, NULL, NULL);

	//Try to create the GLFWwindow.
	CHZ_CORE_ASSERT_NEQ(glfw_window, NULL, "GLFW failed to create the window.\n");
	if (!glfw_window) return NULL;

	//Make the graphics context.
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
	new_window->__Update__ 		= Update;


	//Initialize the CHazelWindowGLFW.
	new_WindowGLFW->obj 			= new_WindowGLFW;
	new_WindowGLFW->__OnDestroy__ 	= OnDestroy;
	new_WindowGLFW->m_Window 		= glfw_window;

	return new_window;
}