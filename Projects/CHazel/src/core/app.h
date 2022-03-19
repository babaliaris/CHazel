#ifndef CHAZEL_APP_H
#define CHAZEL_APP_H

#include "window.h"

typedef struct CHazelApp
{
	struct CHazelApp* obj;

	CHazelWindow *m_Window;

	void (*__Run__)(struct CHazelApp *obj);

	void (*__OnDestroy__)(struct CHazelApp *obj);
}
CHazelApp;


CHazelApp* CHazelCreateApp();

CHazelApp* CHazelEntryPoint();

#endif