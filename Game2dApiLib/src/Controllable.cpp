#include "Controllable.h"
using namespace input;

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
		commandMap.at(input)->Execute();
	}
	catch (const std::out_of_range& err)
	{
		// Do nothing
	}
}

void Controllable::SetCommandInput(std::reference_wrapper <Input> input, std::reference_wrapper <Command> command)
{
	commandMap.insert(input, command);
}