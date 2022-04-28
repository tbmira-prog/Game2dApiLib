#ifndef _UNIQUE_
#define _UNIQUE_

#include <stdexcept>

namespace util
{
	class InvalidInstantiation : public std::exception
	{
		const char* what() const override { return "Tried to instantiate twice a Unique class!\n"; }
	};

	template<typename T>
	class Unique
	{
	public:
		Unique()
		{
			if (instantiated)
				throw InvalidInstantiation();

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

}

#endif // _UNIQUE_