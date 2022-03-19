#ifndef CHAZEL_APP_H
#define CHAZEL_APP_H

#include "window.h"


/**
 * The main funionality of CHazel.
 * 
 * Code Conventions:
 *		1) Member variables start with m_
 *		2) Methods start with a capital letter (camelcase words).
 *		3) Anything that starts and ends with __ (double underscores)
			are private. YOU SHOULD not use them unless you want to hack.
*/
typedef struct CHazelApp
{
	//The instance of this struct.If obj is declared as void *
	//it means that this struct is an interface.
	struct CHazelApp* obj;

	//-_-_-_-_-_-_-_-_-_-_Member Variables-_-_-_-_-_-_-_-_-_-_//

	CHazelWindow *m_Window;
	
	//-_-_-_-_-_-_-_-_-_-_Member Variables-_-_-_-_-_-_-_-_-_-_//


	//*************************Methods*************************//

	void (*__Run__)(struct CHazelApp *obj);

	void (*__OnDestroy__)(struct CHazelApp *obj);

	//*************************Methods*************************//
}
CHazelApp;


CHazelApp* CHazelCreateApp();

CHazelApp* CHazelEntryPoint();

#endif