#include "pch.h"
#include <core/render/rendererAPI.h>
#include <core/core.h>
#include <core/debug/coreLogger.h>
#include <glad/glad.h>

#include <GLFW/glfw3.h>


void SetClearColor(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}



void ClearColorBuffer()
{
	glClear(GL_COLOR_BUFFER_BIT);
}



void SetViewport(int x, int y, int width, int height)
{
	glViewport(x, y, width, height);
}



void OnDestroy(struct CHazelRendererAPI *obj)
{
	CHZ_CORE_IMPORTANT("...........................CHazelRendererAPI->OnDestroy()");
}




CHazelRendererAPI* CHazelCreateRendererAPI()
{
	//Initialize GLAD.
	int success = 0;
	CHZ_CORE_ASSERT_EQ(success = gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress ), 1, "GLAD failed to be initialized...");
	if (!success) return NULL;

	//Create the new instance.
	CHazelRendererAPI* new_api = (CHazelRendererAPI *)CHZ_NEW(CHazelRendererAPI);

	//Initialize it.
	new_api->SetClearColor 		= SetClearColor;
	new_api->ClearColorBuffer 	= ClearColorBuffer;
	new_api->SetViewport 		= SetViewport;
	new_api->__OnDestroy__ 		= OnDestroy;

	return new_api;
}