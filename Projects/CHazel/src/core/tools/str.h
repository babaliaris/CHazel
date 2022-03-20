#ifndef CHAZEL_STR_H
#define CHAZEL_STR_H
#include <sds.h>



/**
 * SDS encapsulation.
 * 
 * Code Conventions:
 *		1) Member variables start with m_
 *		2) Methods start with a capital letter (camelcase words).
 *		3) Anything that starts and ends with __ (double underscores)
			are private. YOU SHOULD not use them unless you want to hack.
*/
typedef struct CHazelString
{
	//-_-_-_-_-_-_-_-_-_-_Member Variables-_-_-_-_-_-_-_-_-_-_//

	struct CHazelString* obj;

	sds __m_string__;

	//-_-_-_-_-_-_-_-_-_-_Member Variables-_-_-_-_-_-_-_-_-_-_//



	//*************************Methods*************************//


	/**
	 * Get the sds string.
	 * 
	 * @param obj this instance.
	 * @return The encapsulated sds string.
	*/
	sds (*GetSDS)(struct CHazelString *obj);

	/**
	 * Set the update __m_string__.
	 * 
	 * @param obj this instance.
	 * @param updated_string The updated string.
	*/
	void (*SetSDS)(struct CHazelString *obj, sds updated_string);

	/**
	 * It's being called when the instance get's destroyed.
	 * 
	 * @param obj this instance.
	*/
	void (*__OnDestroy__)(struct CHazelString *obj);

	//*************************Methods*************************//
}
CHazelString;



/**
 * Creates a new CHazelString from an sds string.
 * 
 * @param string A c const char * string.
 * @return The new CHazelString instance.
*/
CHazelString* CHazelCreateString(const char *string);

#endif