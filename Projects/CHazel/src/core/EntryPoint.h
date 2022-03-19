#ifndef CHAZEL_ENTRY_POINT_H
#define CHAZEL_ENTRY_POINT_H
#include <core/core.h>
#include <core/app.h>

#ifdef CHZ_ENTRY
int main()
{
	CHazelApp* app = CHazelEntryPoint();

	app->__Run__(app->obj);

	CHZ_DESTROY(app);

	return 0;
}
#endif

#endif