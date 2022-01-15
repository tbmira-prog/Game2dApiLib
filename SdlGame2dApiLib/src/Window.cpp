#ifdef __linux__ 
//linux code goes here // UNDONE Biblioteca para esconder terminal no linux
#elif _WIN32
#include <windows.h>
#else
// ... // UNDONE Biblioteca para esconder terminal em outras plataformas
#endif

#include "SDL_image.h"
#include "Window.h"
using namespace graph::sdl;

void HideConsole()
{
#ifdef __linux__ 
	// Linux code goes here // UNDONE Esconder terminal no linux
#elif _WIN32
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
#else
	// UNDONE Esconder terminal em outras plataformas
#endif
}

Window::Window(int width, int height) : Screen(), pWindow(nullptr), pRenderer(nullptr)
{
	try
	{
		HideConsole();

		if (SDL_Init(SDL_INIT_VIDEO) < 0) // TODO Será possível iniciar o SDL com Audio em AudioPlayer? Ou dever ser feito tudo nesta classe?
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
		// TODO Abort caso falhe em criar janela
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