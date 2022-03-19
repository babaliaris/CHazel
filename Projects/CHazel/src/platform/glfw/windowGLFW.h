#ifndef CHAZEL_WINDOW_GLFW_H
#define CHAZEL_WINDOW_GLFW_H

#include <GLFW/glfw3.h>
#include <core/window.h>

typedef struct CHazelWindowGLFW
{
	//The instance of this struct.If obj is declared as void *
	//it means that this struct is an interface.
	struct CHazelWindowGLFW* obj;

	//-_-_-_-_-_-_-_-_-_-_Member Variables-_-_-_-_-_-_-_-_-_-_//

	GLFWwindow* m_Window;

	//-_-_-_-_-_-_-_-_-_-_Member Variables-_-_-_-_-_-_-_-_-_-_//


	//*************************Methods*************************//

	/**
	 * It's being called when the object gets destroyed.
	 * 
	*/
	void (*__OnDestroy__)(struct CHazelWindowGLFW* obj);

	//*************************Methods*************************//

}
CHazelWindowGLFW;

#endif