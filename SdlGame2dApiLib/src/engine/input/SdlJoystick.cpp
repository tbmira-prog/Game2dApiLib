#include "SdlJoystick.h"
#include "SdlInput.h"

using namespace engine::input::sdl;

SdlJoystick::SdlJoystick(InputGetMode newMode, size_t timeOut_ms) : sdlInput(), Joystick(sdlInput, newMode, timeOut_ms) {}; // TO_DO Construtor primeiro constroi classe base, aqui est� tendo que acontecer o contr�rio

SdlJoystick::~SdlJoystick() {}

void SdlJoystick::PollInput()
{
	sdlInput.sdlEvent.type = SDL_FIRSTEVENT;

	SDL_PollEvent(&sdlInput.sdlEvent);
}

void SdlJoystick :: WaitInput(size_t timeOut_ms)
{
	sdlInput.sdlEvent.type = SDL_FIRSTEVENT;

	SDL_WaitEventTimeout(&sdlInput.sdlEvent, timeOut_ms);
}
