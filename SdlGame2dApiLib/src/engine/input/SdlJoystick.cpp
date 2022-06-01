#include "SdlJoystick.h"
#include "SdlInput.h"

using namespace engine::input::sdl;

SdlJoystick::SdlJoystick(InputGetMode newMode, size_t timeOut_ms) : sdlInput(), Joystick(sdlInput, newMode, timeOut_ms) {}; // TO_DO Construtor primeiro constroi classe base, aqui está tendo que acontecer o contrário

SdlJoystick::~SdlJoystick() {}

void SdlJoystick::PoolInput()
{
	sdlInput.sdlEvent.type = SDL_FIRSTEVENT;

	SDL_PollEvent(&sdlInput.sdlEvent);
}

void SdlJoystick :: WaitInput(size_t timeOut_ms)
{
	sdlInput.sdlEvent.type = SDL_FIRSTEVENT;

	SDL_WaitEventTimeout(&sdlInput.sdlEvent, timeOut_ms);
}
/*
void SdlJoystick::SetInput(engine::input::Input& i)
{
	SdlInput* pInput = dynamic_cast<SdlInput*>(&i);

	if (pInput != nullptr)
		pInput->sdlEvent = sdlInput.sdlEvent;
	else
		pInput->sdlEvent.type = SDL_FIRSTEVENT; // TODO Evento quando nada foi apertado
}
*/