#ifndef CHAZEL_CORE_LOGGER_H
#define CHAZEL_CORE_LOGGER_H

#include <core/debug/logger.h>

#ifdef CHZ_DEBUG
	#define CHZ_CORE_TRACE(...)		printf("[CORE:trace]     "); CHZ_COLORED_PRINT(CHZ_COLOR_END, __VA_ARGS__)
	#define CHZ_CORE_INFO(...)		printf("[CORE:info]      "); CHZ_COLORED_PRINT(CHZ_COLOR_GREEN, __VA_ARGS__)
	#define CHZ_CORE_IMPORTANT(...)	printf("[CORE:important] "); CHZ_COLORED_PRINT(CHZ_COLOR_PURPLE, __VA_ARGS__)
	#define CHZ_CORE_WARN(...)		printf("[CORE:warning]   "); CHZ_COLORED_PRINT(CHZ_COLOR_YELLOW, __VA_ARGS__)
	#define CHZ_CORE_ERROR(...)		printf("[CORE:error]     "); CHZ_COLORED_PRINT(CHZ_COLOR_RED, __VA_ARGS__)

	#define CHZ_CORE_ASSERT_EQ(real, expected, ...)\
	{\
		if ( (real) != (expected) )\
		{\
			CHZ_COLORED_PRINT(CHZ_COLOR_RED, "[CORE:ASSERT_EQ (FAILED)]");\
			CHZ_COLORED_PRINT(CHZ_COLOR_BLUE, "\t[REAL]    : %s\n\t[EXPECTED]: %s", #real, #expected);\
			printf("\t[Message] : "); CHZ_COLORED_PRINT(CHZ_COLOR_GREEN, __VA_ARGS__);\
			CHZ_COLORED_PRINT(CHZ_COLOR_CYAN, "\t[FILE]: %s\n\t[LINE]: %d", __FILE__, __LINE__);\
			printf("Press ENTER to exit...");\
			getchar();\
			exit(-1);\
		}\
	}


	#define CHZ_CORE_ASSERT_NEQ(real, expected, ...)\
	{\
		if ( (real) == (expected) )\
		{\
			CHZ_COLORED_PRINT(CHZ_COLOR_RED, "[CORE:ASSERT_NEQ (FAILED)]");\
			CHZ_COLORED_PRINT(CHZ_COLOR_BLUE, "\t[REAL]    : %s\n\t[EXPECTED]: %s", #real, #expected);\
			printf("\t[Message] : "); CHZ_COLORED_PRINT(CHZ_COLOR_GREEN, __VA_ARGS__);\
			CHZ_COLORED_PRINT(CHZ_COLOR_CYAN, "\t[FILE]: %s\n\t[LINE]: %d", __FILE__, __LINE__);\
			printf("Press ENTER to exit...");\
			getchar();\
			exit(-1);\
		}\
	}


#else
	#define CHZ_CORE_TRACE(...)
	#define CHZ_CORE_INFO(...)
	#define CHZ_CORE_IMPORTANT(...)
	#define CHZ_CORE_WARN(...)
	#define CHZ_CORE_ERROR(...)

	#define CHZ_CORE_ASSERT_EQ(real, expected, ...) real; expected;
	#define CHZ_CORE_ASSERT_NEQ(real, expected, ...) real; expected;

#endif


#endif