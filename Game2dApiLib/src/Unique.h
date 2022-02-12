#ifndef _UNIQUE_
#define _UNIQUE_

#include <cassert>

template<typename T>
class Unique
{
public:
	Unique()
	{
		assert(!instantiated); // TO_DO Trocar assert por throw ou outra coisa, pois assert só funciona em debug
		instantiated = true;
	}

private:
	virtual ~Unique() {}
	friend T;

	Unique(const Unique&) = delete; // TO_DO = delete em todas as classes que não possuirem construtor de cópia
	Unique& operator=(const Unique&) = delete;

	static bool instantiated;
};

template<typename T>
bool Unique<T>::instantiated = false;

#endif // _UNIQUE_