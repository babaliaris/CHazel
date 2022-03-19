#ifndef CHAZEL_CORE_H
#define CHAZEL_CORE_H

#include <stdio.h>
#include <stdlib.h>

#ifdef CHAZEL_IMPLEMENT_GLOBAL_MEM_TRACKER
	unsigned int CHAZEL_NUMBER_OF_ALLOCATIONS = 0;
	unsigned int CHAZEL_NUMBER_OF_DEALLOCATIONS = 0;
#else
	extern unsigned int CHAZEL_NUMBER_OF_ALLOCATIONS;
	extern unsigned int CHAZEL_NUMBER_OF_DEALLOCATIONS;
#endif


#define CHZ_NEW(struct_)\
	malloc( sizeof(struct_) );\
	CHAZEL_NUMBER_OF_ALLOCATIONS++


#define CHZ_DESTROY(object)\
	object->__OnDestroy__(object);\
	free(object);\
	object = NULL;\
	CHAZEL_NUMBER_OF_DEALLOCATIONS++


#endif

