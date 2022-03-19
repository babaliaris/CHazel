#ifndef CHAZEL_LOGGER_H
#define CHAZEL_LOGGER_H

#if defined(CHZ_LINUX) && defined(CHZ_DEBUG)
	#define CHZ_COLOR_RED 		"\e[1;31m"
	#define CHZ_COLOR_GREEN 	"\e[1;32m"
	#define CHZ_COLOR_YELLOW 	"\e[1;33m"
	#define CHZ_COLOR_BLUE 		"\e[1;34m"
	#define CHZ_COLOR_CYAN 		"\e[1;36m"
	#define CHZ_COLOR_PURPLE	"\e[1;35m"
	#define CHZ_COLOR_END 		"\e[0m"

	#define CHZ_VA_ARGS(...) , ##__VA_ARGS__

	#define CHZ_COLORED_PRINT(color, ...)\
		printf(color);\
		printf(__VA_ARGS__);\
		printf("\n");\
		printf(CHZ_COLOR_END)



#elif defined(CHZ_WINDOW) && defined(CHZ_DEBUG)

	#define CHZ_COLOR_RED		4
	#define CHZ_COLOR_GREEN		2
	#define CHZ_COLOR_YELLOW	6
	#define CHZ_COLOR_BLUE		1
	#define CHZ_COLOR_CYAN		3
	#define CHZ_COLOR_PURPLE	5
	#define CHZ_COLOR_END		7


	#define CHZ_COLORED_PRINT(color, ...)\
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);\
		printf(__VA_ARGS__);\
		printf("\n");\
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), CHZ_COLOR_END)




#else
	#define CHZ_COLOR_RED
	#define CHZ_COLOR_GREEN
	#define CHZ_COLOR_YELLOW
	#define CHZ_COLOR_BLUE
	#define CHZ_COLOR_CYAN
	#define CHZ_COLOR_PURPLE
	#define CHZ_COLOR_END

	#define CHZ_COLORED_PRINT(color, ...)

#endif

#endif