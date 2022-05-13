#include "SdlInput.h"
using namespace engine::input::sdl;

SdlInput::SdlInput() : sdlEvent() {};

SdlInput::SdlInput(const SDL_Event& e) : sdlEvent(e) {};

SdlInput::~SdlInput() {}

bool SdlInput::operator==(const Input& otherInput) const
{
	const SdlInput* pOtherSdlInput = dynamic_cast<const SdlInput*>(&otherInput);

	if (pOtherSdlInput)
	{
		return *this == pOtherSdlInput->sdlEvent;
	}
	else
		return false;
}

bool SdlInput::operator==(const SDL_Event& e) const
{
	if (this->sdlEvent.type == e.type) // TO_DO Pensar no que é importante comparar para ver se dois inputs SDL são iguais, para cada tipo de input
	{
		switch (this->sdlEvent.type)
		{
		case SDL_AUDIODEVICEADDED:
		case SDL_AUDIODEVICEREMOVED:
			return false; // adevice

		case SDL_CONTROLLERAXISMOTION:
			return false; // caxis

		case SDL_CONTROLLERBUTTONDOWN:
		case SDL_CONTROLLERBUTTONUP:
			return false; // cbutton

		case SDL_CONTROLLERDEVICEADDED:
		case SDL_CONTROLLERDEVICEREMOVED:
		case SDL_CONTROLLERDEVICEREMAPPED:
			return false; // cdevice

		case SDL_DOLLARGESTURE:
		case SDL_DOLLARRECORD:
			return false; // dgesture

		case SDL_DROPFILE:
		case SDL_DROPTEXT:
		case SDL_DROPBEGIN:
		case SDL_DROPCOMPLETE:
			return false; // drop

		case SDL_FINGERMOTION:
		case SDL_FINGERDOWN:
		case SDL_FINGERUP:
			return false; // tfinger

		case SDL_FIRSTEVENT:
			return false;

		case SDL_KEYDOWN:
		case SDL_KEYUP:
			return this->sdlEvent.key.keysym.sym ==
				e.key.keysym.sym;

		case SDL_JOYAXISMOTION:
			return false; // jaxis

		case SDL_JOYBALLMOTION:
			return false; // jball

		case SDL_JOYHATMOTION:
			return false; // jhat

		case SDL_JOYBUTTONDOWN:
		case SDL_JOYBUTTONUP:
			return false; // jbutton

		case SDL_JOYDEVICEADDED:
		case SDL_JOYDEVICEREMOVED:
			return false; // jdevice

		case SDL_MOUSEMOTION:
			return true; // motion

		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
			return this->sdlEvent.button.button == e.button.button &&
				this->sdlEvent.button.clicks == e.button.clicks;

		case SDL_MOUSEWHEEL:
			return this->sdlEvent.wheel.direction ==
				e.wheel.direction; // wheel

		case SDL_MULTIGESTURE:
			return false; // mgesture

		case SDL_QUIT:
			return false; // quit

		case SDL_SYSWMEVENT:
			return false; // syswm

		case SDL_TEXTEDITING:
			return false; // edit

		case SDL_TEXTINPUT:
			return false; // text

		case SDL_USEREVENT:
			return false; // user

		case SDL_WINDOWEVENT:
			return false; // window

		default:
			return false;
		}
	}
	else
		return false;
}

bool SdlInput::Quit() const
{
	return sdlEvent.type == SDL_QUIT;
}

bool SdlInput::Undo() const
{
	return sdlEvent.type == SDL_KEYUP && sdlEvent.key.keysym.sym == SDLK_UNDO;
}

bool SdlInput::Redo() const
{
	return sdlEvent.type == SDL_KEYUP && sdlEvent.key.keysym.sym == SDLK_AGAIN;
}