#include "SdlAudioPlayer.h"
using namespace engine::audio::sdl;

#include <SDL.h>

SdlAudioPlayer::SdlAudioPlayer() : AudioPlayer()
{
    try
    {
        if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0)
            throw  FailedToInitializateSDLAudio(); // TO_DO Notificar usuário sobre erro

        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) // UNDONE Usuário poder configurar MONO ou STEREO
            throw  FailedToInitializateSDLAudio(); // TO_DO Notificar usuário sobre erro

    }
    catch(...)
    {
        muted = true;
    }
}

SdlAudioPlayer::~SdlAudioPlayer()
{
    SDL_QuitSubSystem(SDL_INIT_AUDIO);
}