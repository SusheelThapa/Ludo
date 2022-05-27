#pragma once

#ifdef _WIN32
#include <SDL.h>

#elif __linux__
#include <SDL2/SDL.h>

#endif

#include <iostream>
#include <string>

class Window
{

private:
	std::string title;

	int width;

	int height;

	bool closed = false;

	SDL_Window *window = nullptr;

	SDL_Event e;

public:
	SDL_Renderer *renderer = nullptr;

private:
	bool init();

public:
	Window();
	Window(std::string);
	Window(std::string, int width, int height);

	~Window();

	void handleEvent(SDL_Event &);

	void clear(SDL_Color color);

	void present();

	bool isWindowClosed();

	int getWidth();

	int getHeight();
};
