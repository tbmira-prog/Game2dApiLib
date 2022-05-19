#include "ObjectVector.h"
using namespace game;

#include "engine/audio/NullAudio.h"

ObjectVector::ObjectVector() : images(), controllables(), sounds(), song(engine::audio::noSong), songAction(engine::audio::SongAction::STOP)
{}

ObjectVector::~ObjectVector()
{}

void ObjectVector::Push(GameObject& object)
{
	images.push_back(object.image);
	controllables.push_back(object);
	sounds.push_back(object.soundEffect);
}

void ObjectVector::Pop()
{
	images.pop_back();
	controllables.pop_back();
	sounds.pop_back();
}

void ObjectVector::Remove(const GameObject& object) // UNDONE Implementar esta função Remove(GameObject)
{

}

void ObjectVector::Clear()
{
	images.clear();
	controllables.clear();
	sounds.clear();
}