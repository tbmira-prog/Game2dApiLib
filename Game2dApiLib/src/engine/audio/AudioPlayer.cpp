#include "AudioPlayer.h"
using namespace engine::audio;

void AudioPlayer::ControlMusic(Song& song, const SongAction action)
{
	if (song == noSong)
		return;

	switch (action)
	{
	case SongAction::PLAY:
		if (song != currentSong)
		{
			//Stop(currentSong);
			//Play(song);
			currentSong.Stop(*this);
			song.Play(*this);
		}
		else if (!currentSong.Playing())
			//Play(currentSong);
			currentSong.Play(*this);
		break;
	case SongAction::PAUSE:
		if (currentSong.Playing())
			//Pause(currentSong);
			currentSong.Pause(*this);
		break;
	case SongAction::STOP:
		if (currentSong.Playing())
			//Stop(currentSong);
			currentSong.Stop(*this);
		break;
	}
}