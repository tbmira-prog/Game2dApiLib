#ifndef _OBJECT_VECTOR_
#define _OBJECT_VECTOR_

#include "GameObject.h"

#include "engine/audio/AudioManager.h"
#include "engine/graph/GraphManager.h"
#include "engine/input/InputManager.h"

namespace game {
	class ObjectVector
	{
	public:
		ObjectVector();
		~ObjectVector();

		void Push(GameObject& object);
		
		void Pop();
		void Remove(const GameObject& object);

		void Clear();

		inline const engine::graph::ImageVector& Images() { return images; } // TO_DO Impedir que modifiquem a ordem dos vetores fora de Game
		inline const engine::input::ControllableVector& Controllables() { return controllables; } // TO_DO Retornar const & ou só & ?
		inline const engine::audio::SoundVector& Sounds() { return sounds; }
		inline engine::audio::Song& CurrentSong() { return song; }
		inline const engine::audio::SongAction SongAction() { return songAction; }

	private:
		std::vector<game::GameObject*> objects;
		engine::graph::ImageVector images;
		engine::input::ControllableVector controllables;
		engine::audio::SoundVector sounds;
		engine::audio::Song& song; // TODO Arrumar song, como tocar mais de uma ao mesmo tempo?
		engine::audio::SongAction songAction;
	};
}

#endif // _OBJECT_VECTOR_