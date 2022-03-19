#include "pch.h"
#include "app.h"
#include "core.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>


CHazelWindow* CHazelCreateWindow(const char *title, int width, int height);


static void Run(struct CHazelApp *obj)
{
	if ( !gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) )
	{
		printf("GLAD cound not be initialized...");
		glfwTerminate();
		return;
	}

	GLFWwindow* glfw_win = obj->m_Window->GetNativeWindow( (void *)obj->m_Window->obj );

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(glfw_win))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		obj->m_Window->Update( (void *)obj->m_Window->obj );
	}

	glfwTerminate();
}




static void OnDestroy(struct CHazelApp *obj)
{
	printf("...........................CHazelApp->OnDestroy()\n");
	CHZ_DESTROY(obj->m_Window);
}




CHazelApp* CHazelCreateApp()
{
	CHazelApp* new_app = (CHazelApp *)CHZ_NEW(CHazelApp);

	if (new_app == NULL)
	{
		//TODO log something here.
		return NULL;
	}

	//Store this object into itself.
	new_app->obj = new_app;
	new_app->m_Window = CHazelCreateWindow("CHazel Engine", 1024, 720);

	new_app->__Run__ 		= Run;
	new_app->__OnDestroy__ 	= OnDestroy;

	return new_app;
}