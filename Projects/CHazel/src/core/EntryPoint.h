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

	CHZ_IMPORTANT("ALLOCATIONS = %d    DEALLOCATIONS = %d", CHAZEL_NUMBER_OF_ALLOCATIONS, CHAZEL_NUMBER_OF_DEALLOCATIONS);

	CHZ_ASSERT_EQ(CHAZEL_NUMBER_OF_ALLOCATIONS, CHAZEL_NUMBER_OF_DEALLOCATIONS, "Memory Leak!!!");

	return 0;
}
#endif

#endif