#include "SdlInputGetter.h"
#include "SdlInput.h"

using namespace input::sdl;

void SdlInputGetter :: GetInput(input::Input& i)
{
	event.type = SDL_FIRSTEVENT;

	if(SDL_PollEvent(&event))
		SetInput(i);
}

void SdlInputGetter :: WaitInput(input::Input& input, size_t timeOut_ms)
{
	event.type = SDL_FIRSTEVENT;

	if(SDL_WaitEventTimeout(&event, timeOut_ms))
		SetInput(input);
}

void SdlInputGetter :: SetInput(Input& i)
{
	SdlInput* pInput = dynamic_cast<SdlInput*>(&i);

	if (pInput != nullptr)
		pInput->sdlEvent = event;
	else
		pInput->sdlEvent.type = SDL_FIRSTEVENT; // TODO Evento quando nada foi apertado
}