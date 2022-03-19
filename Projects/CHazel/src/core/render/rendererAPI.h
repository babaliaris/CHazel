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

	/**
	 * Set the clear color.
	 * 
	 * @param r Red channel (Normalized).
	 * @param g Green channel (Normalized).
	 * @param b Blue channel (Normalized).
	 * @param a Alpha channel (Normalized).
	*/
	void (*SetClearColor)(float r, float g, float b, float a);

	/**
	 * Clear the color buffer.
	 * 
	*/
	void (*ClearColorBuffer)();

	/**
	 * Set the viewport.
	 * 
	*/
	void (*SetViewport)(int x, int y, int width, int height);


	/**
	 * It's being called when the instance get's destroyed.
	 * 
	 * @param obj this instance.
	*/
	void (*__OnDestroy__)(struct CHazelRendererAPI *obj);

	//*************************Methods*************************//
}
CHazelRendererAPI;

#endif