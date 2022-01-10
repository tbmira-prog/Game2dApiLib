#include "Controllable.h"
using namespace input;

#include <stdexcept>

Controllable::Controllable() : commandMap()
{

}

Controllable::~Controllable()
{
	commandMap.clear();
}

void Controllable::HandleInput(std::reference_wrapper <Input> input)
{
	try
	{
		commandMap.at(input).get().Execute();
	}
	catch (const std::out_of_range& err)
	{
		// Do nothing
	}
}

void Controllable::SetCommandInput(const Input& input, const Command& command)
{
	commandMap.insert(input, command);
}