#include "pch.h"
#include "app.h"

#define CHAZEL_IMPLEMENT_GLOBAL_MEM_TRACKER
#include <core/core.h>

#include <core/debug/coreLogger.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <core/tools/str.h>

/**
 * This function is being implemented on platform specific files.
 * Check src/platform/
 * 
 * @return The CHazelWindow window instance.
*/
CHazelWindow* CHazelCreateWindow(const char *title, int width, int height);


/**
 * This function is being implemented on platform specific files.
 * Check src/platform/
 * 
 * @return The CHazelRendererAPI instance.
*/
CHazelRendererAPI* CHazelCreateRendererAPI();


static void Run(struct CHazelApp *obj)
{
	//Exit the application if no window.
	if (obj->m_Window == NULL) return;

	//Set the clear color to dark grey.
	obj->m_RendererAPI->SetClearColor(0.35, 0.35, 0.35, 1);

	GLFWwindow* glfw_win = obj->m_Window->GetNativeWindow( (void *)obj->m_Window->obj );

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(glfw_win))
	{
		//Clear the color buffer.
		obj->m_RendererAPI->ClearColorBuffer();

		//Update the window.
		obj->m_Window->__Update__( (void *)obj->m_Window->obj );
	}
}




static void OnDestroy(struct CHazelApp *obj)
{
	CHZ_CORE_IMPORTANT("...........................CHazelApp->OnDestroy()");
	CHZ_DESTROY(obj->m_Window);
	CHZ_DESTROY(obj->m_RendererAPI);
}




CHazelApp* CHazelCreateApp()
{
	//Create the app.
	CHazelApp* new_app = (CHazelApp *)CHZ_NEW(CHazelApp);

	//Store this object into itself.
	new_app->obj = new_app;
	new_app->m_Window = CHazelCreateWindow("CHazel Engine", 1024, 720);
	new_app->m_RendererAPI = CHazelCreateRendererAPI();

	//Initialize the new CHazelApp.
	new_app->__Run__ 		= Run;
	new_app->__OnDestroy__ 	= OnDestroy;

	return new_app;
}