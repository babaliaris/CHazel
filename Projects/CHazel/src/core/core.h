#ifndef CHAZEL_CORE_H
#define CHAZEL_CORE_H
#include <stdio.h>
#include <stdlib.h>

#define CHZ_NEW(struct_)\
	malloc( sizeof(struct_) )


#define CHZ_DESTROY(object)\
	object->__OnDestroy__(object);\
	free(object);\
	object = NULL


#endif

