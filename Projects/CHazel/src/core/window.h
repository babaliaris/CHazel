#ifndef CHAZEL_WINDOW_H
#define CHAZEL_WINDOW_H

typedef struct CHazelWindow
{
	void* obj;

	void (*__OnDestroy__)(void *obj);

	int (*GetWidth)(void* obj);

	int (*GetHeight)(void* obj);

	void* (*GetNativeWindow)(void* obj);

	void (*Update)(void* obj);
}
CHazelWindow;

#endif