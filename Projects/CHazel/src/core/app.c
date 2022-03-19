#include "pch.h"
#include "app.h"
#include "core.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

static void Run(struct CHazelApp *this)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
	{
		printf("GLFW cound not be initialized...");
		return;
	}

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		printf("GLFW cound not be initialized...");
		glfwTerminate();
		return;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if ( !gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) )
	{
		printf("GLAD cound not be initialized...");
		glfwTerminate();
		return;
	}

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
}




static void OnDestroy(struct CHazelApp *this)
{
	printf("OnDestroy!\n");
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

	new_app->__Run__ 		= Run;
	new_app->__OnDestroy__ 	= OnDestroy;

	return new_app;
}