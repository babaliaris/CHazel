#ifndef CHAZEL_CLIENT_LOGGER_H
#define CHAZEL_CLIENT_LOGGER_H

#include <core/debug/logger.h>

#ifdef CHZ_DEBUG
	#define CHZ_TRACE(...)		printf("[APP:trace]     "); CHZ_COLORED_PRINT(CHZ_COLOR_END, __VA_ARGS__)
	#define CHZ_INFO(...)		printf("[APP:info]      "); CHZ_COLORED_PRINT(CHZ_COLOR_GREEN, __VA_ARGS__)
	#define CHZ_IMPORTANT(...)	printf("[APP:important] "); CHZ_COLORED_PRINT(CHZ_COLOR_PURPLE, __VA_ARGS__)
	#define CHZ_WARN(...)		printf("[APP:warning]   "); CHZ_COLORED_PRINT(CHZ_COLOR_YELLOW, __VA_ARGS__)
	#define CHZ_ERROR(...)		printf("[APP:error]     "); CHZ_COLORED_PRINT(CHZ_COLOR_RED, __VA_ARGS__)


	#define CHZ_ASSERT_EQ(real, expected, ...)\
	{\
		if ( (real) != (expected) )\
		{\
			CHZ_COLORED_PRINT(CHZ_COLOR_RED, "[APP:ASSERT_EQ (FAILED)]");\
			CHZ_COLORED_PRINT(CHZ_COLOR_BLUE, "\t[REAL]    : %s\n\t[EXPECTED]: %s", #real, #expected);\
			printf("\t[Message] : "); CHZ_COLORED_PRINT(CHZ_COLOR_GREEN, __VA_ARGS__);\
			CHZ_COLORED_PRINT(CHZ_COLOR_CYAN, "\t[FILE]: %s\n\t[LINE]: %d", __FILE__, __LINE__);\
			printf("Press ENTER to exit...");\
			getchar();\
			exit(-1);\
		}\
	}


	#define CHZ_ASSERT_NEQ(real, expected, ...)\
	{\
		if ( (real) == (expected) )\
		{\
			CHZ_COLORED_PRINT(CHZ_COLOR_RED, "[APP:ASSERT_NEQ (FAILED)]");\
			CHZ_COLORED_PRINT(CHZ_COLOR_BLUE, "\t[REAL]    : %s\n\t[EXPECTED]: %s", #real, #expected);\
			printf("\t[Message] : "); CHZ_COLORED_PRINT(CHZ_COLOR_GREEN, __VA_ARGS__);\
			CHZ_COLORED_PRINT(CHZ_COLOR_CYAN, "\t[FILE]: %s\n\t[LINE]: %d", __FILE__, __LINE__);\
			printf("Press ENTER to exit...");\
			getchar();\
			exit(-1);\
		}\
	}


#else
	#define CHZ_TRACE(...)
	#define CHZ_INFO(...)
	#define CHZ_IMPORTANT(...)
	#define CHZ_WARN(...)
	#define CHZ_ERROR(...)

	#define CHZ_CORE_ASSERT_EQ(real, expected, ...) real; expected;
	#define CHZ_CORE_ASSERT_NEQ(real, expected, ...) real; expected;

#endif

#endif