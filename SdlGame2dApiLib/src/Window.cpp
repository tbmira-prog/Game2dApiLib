#include "Window.h"
using namespace graph::sdl;

Window::Window() : Screen(), pWindow(nullptr), pRenderer(nullptr)
{
	try
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
			throw;
		//TO DO SCreen width
		//pWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (pWindow == NULL)
			throw;

		pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
		if (pRenderer == NULL)
			throw;

		//if (!(IMG_Init(imgFlags) & imgFlags))
		//	throw;
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

//	IMG_Quit();
	SDL_Quit();
}

void Window::Clear()
{
	SDL_RenderClear(pRenderer);
}