#ifndef _TERMINAL_
#define _TERMINAL_

#include <iostream>

#include "Screen.h"

namespace graph
{
	namespace terminal
	{
		class Terminal : public Screen
		{
		public:
			Terminal() {}
			~Terminal() {}

			void Clear();
			
			inline std::ostream& Get()
			{
				return std::cout;
			}

		};

	}
}

#endif // _TERMINAL_
