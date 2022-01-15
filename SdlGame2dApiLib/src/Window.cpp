#ifdef __linux__ 
//linux code goes here
#elif _WIN32
#include <windows.h>
#else
// ...
#endif

#include "SDL_image.h"
#include "Window.h"
using namespace graph::sdl;

void HideConsole()
{
#ifdef __linux__ 
	// Linux code goes here
#elif _WIN32
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
#else
	// ...
#endif
}


Window::Window(int width, int height) : Screen(), pWindow(nullptr), pRenderer(nullptr)
{
	try
	{
		HideConsole();

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
			throw;
		
		pWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		if (pWindow == NULL)
			throw;

		pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
		if (pRenderer == NULL)
			throw;

		if (!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG))
			throw;
	}
	catch (...)
	{
		// Abort
	}
}

Window::~Window()
{
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	pWindow = nullptr;
	pRenderer = nullptr;

	IMG_Quit();
	SDL_Quit();
}

void Window::Clear()
{
	SDL_RenderClear(pRenderer);
}