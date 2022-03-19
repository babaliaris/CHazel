#ifndef CHAZEL_WINDOW_H
#define CHAZEL_WINDOW_H


/**
 * Window interface.
 * 
 * Code Conventions:
 *		1) Member variables start with m_
 *		2) Methods start with a capital letter (camelcase words).
 *		3) Anything that starts and ends with __ (double underscores)
			are private. YOU SHOULD not use them unless you want to hack.
*/
typedef struct CHazelWindow
{
	//The instance of this struct.If obj is declared as void *
	//it means that this struct is an interface.
	void* obj;

	//*************************Methods*************************//

	/**
	 * Get the width of the window.
	 * 
	 * @return The width of the window.
	*/
	int (*GetWidth)(void* obj);

	/**
	 * Get the height of the window.
	 * 
	 * @return The height of the window.
	*/
	int (*GetHeight)(void* obj);

	/**
	 * Get the native window.
	 * 
	*/
	void* (*GetNativeWindow)(void* obj);

	/**
	 * Polls the events and swaps the buffers.
	 * 
	*/
	void (*__Update__)(void* obj);


	/**
	 * It's being called when the object gets destroyed.
	 * 
	*/
	void (*__OnDestroy__)(void *obj);

	//*************************Methods*************************//
}
CHazelWindow;

#endif