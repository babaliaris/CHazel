#ifndef CHAZEL_RENDERER_API_H
#define CHAZEL_RENDERER_API_H


/**
* The main funionality of CHazel.
* 
* Code Conventions:
*		1) Member variables start with m_
*		2) Methods start with a capital letter (camelcase words).
*		3) Anything that starts and ends with __ (double underscores)
*			are private. YOU SHOULD not use them unless you want to hack.
* 
* This does not have and obj member because it acts as a "static class".
*
*
*/
typedef struct CHazelRendererAPI
{
	//*************************Methods*************************//

	void (*SetClearColor)(float r, float g, float b, float a);

	void (*ClearColorBuffer)();

	void (*SetViewport)(int x, int y, int width, int height);

	void (*__OnDestroy__)(struct CHazelRendererAPI *obj);

	//*************************Methods*************************//
}
CHazelRendererAPI;

#endif