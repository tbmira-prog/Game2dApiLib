#include "Text.h"
#include "Terminal.h"
using namespace graph::terminal;

Text::Text() : text() {}

Text::Text(std::string newText) : text(newText) {}

Text::~Text() {}

void Text::Print(Screen& screen) const
{
	Terminal* pTerminal = dynamic_cast<Terminal*>(&screen);
	if (pTerminal != nullptr)
	{
		pTerminal->Get() << text;
	}
}