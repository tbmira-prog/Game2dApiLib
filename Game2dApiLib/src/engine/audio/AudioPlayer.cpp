#include "AudioPlayer.h"
using namespace engine::audio;

void AudioPlayer::ControlMusic(Song& song, const SongAction action) // UNDONE Função muito grande
{
	if (song == noSong)
		return;

	switch (action)
	{
	case SongAction::PLAY:
		if (song == currentSong)
		{
			if (!currentSong.Playing())
				currentSong.Play(*this);
		}
		else
		{
			currentSong.Stop(*this);
			currentSong = song;
			song.Play(*this);
		}
		break;
	case SongAction::PAUSE:
		currentSong.Pause(*this);
		break;
	case SongAction::STOP:
		currentSong.Stop(*this);
		currentSong = noSong;
		break;
	}
}