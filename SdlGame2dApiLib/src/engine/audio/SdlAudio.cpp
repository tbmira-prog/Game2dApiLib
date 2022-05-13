#include "SdlAudio.h"
using namespace engine::audio::sdl;

SdlSoundEffect::SdlSoundEffect() : SoundEffect(), pChunk() {}

SdlSoundEffect::SdlSoundEffect(Mix_Chunk* pNewChunk) : SoundEffect(), pChunk(pNewChunk, DeleteChunk) {}

SdlSoundEffect::SdlSoundEffect(std::shared_ptr<Mix_Chunk> pNewChunk) : SoundEffect(), pChunk(pNewChunk)
{
	if (auto pDel = std::get_deleter<void(*)(Mix_Chunk*)>(pChunk))
		if (*pDel != DeleteChunk)
			pChunk.reset(pNewChunk.get(), DeleteChunk);
}

SdlSoundEffect::SdlSoundEffect(const std::string& filePath) : SoundEffect(), pChunk()
{
	ChangeChunk(filePath);
}

SdlSoundEffect::SdlSoundEffect(const SdlSoundEffect& otherSoundEffect) : SoundEffect(otherSoundEffect), pChunk(otherSoundEffect.pChunk) {}

SdlSoundEffect& SdlSoundEffect::operator=(const SdlSoundEffect& otherSoundEffect)
{
	pChunk = otherSoundEffect.pChunk;
}

SdlSoundEffect::~SdlSoundEffect() {}

void SdlSoundEffect::ChangeChunk(const std::string& filePath)
{
	Mix_Chunk* pNewChunk = Mix_LoadWAV(filePath.c_str());
	if (!pNewChunk)
		throw  InvalidChunk();

	pChunk.reset(pNewChunk, DeleteChunk);
}

void SdlSoundEffect::Play(AudioPlayer& audioPlayer)
{
//	SdlAudioPlayer* pSpeaker = dynamic_cast<SdlAudioPlayer*>(&audioPlayer);

//	if (pSpeaker != nullptr)
//	{
		Mix_PlayChannel(-1, pChunk.get(), 0);
//	}
}

SdlMusic::SdlMusic() : Song(), pMusic() {}

SdlMusic::SdlMusic(Mix_Music* pNewMusic) : Song(), pMusic(pNewMusic, DeleteMusic) {}

SdlMusic::SdlMusic(std::shared_ptr<Mix_Music> pNewMusic) : Song(), pMusic(pNewMusic)
{
	if (auto pDel = std::get_deleter<void(*)(Mix_Music*)>(pMusic))
		if (*pDel != DeleteMusic)
			pMusic.reset(pNewMusic.get(), DeleteMusic);
}

SdlMusic::SdlMusic(const std::string& filePath) : Song(), pMusic()
{
	ChangeMusic(filePath);
}

SdlMusic::SdlMusic(const SdlMusic& otherMusic) : Song(otherMusic), pMusic(otherMusic.pMusic) {}

SdlMusic& SdlMusic::operator=(const SdlMusic& otherMusic)
{
	pMusic = otherMusic.pMusic;
}

SdlMusic::~SdlMusic() {}

void SdlMusic::ChangeMusic(const std::string& filePath)
{
	Mix_Music* pNewMusic = Mix_LoadMUS(filePath.c_str());
	if (!pNewMusic)
		throw  InvalidMusic();

	pMusic.reset(pNewMusic, DeleteMusic);
}

void SdlMusic::Play(AudioPlayer& audioPlayer)
{
	//	SdlAudioPlayer* pSpeaker = dynamic_cast<SdlAudioPlayer*>(&audioPlayer);

	//	if (pSpeaker != nullptr)
	if(!Mix_PlayingMusic())
		Mix_PlayMusic(pMusic.get(), -1);
	else if(Mix_PausedMusic())
		Mix_ResumeMusic();

	playing = true;
}

void SdlMusic::Pause(AudioPlayer& audioPlayer)
{
	//	SdlAudioPlayer* pSpeaker = dynamic_cast<SdlAudioPlayer*>(&audioPlayer);

	//	if (pSpeaker != nullptr)
		Mix_PauseMusic();
	playing = false;
}

void SdlMusic::Stop(AudioPlayer& audioPlayer)
{
	//	SdlAudioPlayer* pSpeaker = dynamic_cast<SdlAudioPlayer*>(&audioPlayer);

	//	if (pSpeaker != nullptr)
		Mix_HaltMusic();
	playing = false;
}