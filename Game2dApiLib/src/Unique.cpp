#include "Unique.h"

#include <cassert>

bool Unique::instantiated = false;

Unique::Unique()
{
	assert(!instantiated);
	instantiated = true;
}

Unique::~Unique() {}