#include "pch.h"
#include "str.h"
#include <core/core.h>
#include <core/debug/coreLogger.h>
#include <core/app.h>


static sds GetSDS(struct CHazelString *obj)
{
	return obj->__m_string__;
}




static void SetSDS(struct CHazelString *obj, sds updated_string)
{
	obj->__m_string__ = updated_string;
}




static void OnDestroy(struct CHazelString *obj)
{
	CHZ_CORE_IMPORTANT("...........................CHazelString->OnDestroy()");
	sdsfree(obj->__m_string__);
}


//Track memory allocations and dealocations
//in the sds (string library) side.
void SDSCallback(int isOnNew)
{
	if (isOnNew)
		CHAZEL_NUMBER_OF_ALLOCATIONS++;

	else
		CHAZEL_NUMBER_OF_DEALLOCATIONS++;
}



static void InitializeMembers(CHazelString* new_string)
{
	new_string->obj 			= new_string;
	new_string->GetSDS 			= GetSDS;
	new_string->SetSDS 			= SetSDS;
	new_string->__OnDestroy__ 	= OnDestroy;
}




CHazelString* CHazelCreateString(const char *string)
{
	//Create the new string.
	CHazelString* new_string = (CHazelString *)CHZ_NEW(CHazelString);

	//Set sds memory tracker callback.
	sdsSetCHazelStringMemoryTrackerCallback(SDSCallback);

	//Initialize it.
	new_string->__m_string__ = sdsnew(string);
	InitializeMembers(new_string);

	return new_string;
}
