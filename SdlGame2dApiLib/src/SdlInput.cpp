#include "SdlInput.h"
using namespace input::sdl;

bool SdlInput :: operator==(const Input& otherInput) const
{
	const SdlInput* otherSdlInput = dynamic_cast<const SdlInput*>(&otherInput);

	if (otherSdlInput)
	{
		if (this->sdlEvent.type == otherSdlInput->sdlEvent.type) // TO_DO Pensar no que é importante comparar para ver se dois inputs SDL são iguais, para cada tipo de input
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
					   otherSdlInput->sdlEvent.key.keysym.sym;

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
				return this->sdlEvent.button.button == otherSdlInput->sdlEvent.button.button &&
					   this->sdlEvent.button.clicks == otherSdlInput->sdlEvent.button.clicks;

			case SDL_MOUSEWHEEL:
				return this->sdlEvent.wheel.direction ==
					   otherSdlInput->sdlEvent.wheel.direction; // wheel

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
	else
		return false;
}