#ifndef _TEXT_
#define _TEXT_

#include <string>

#include "Image.h"

namespace graph
{
	namespace terminal
	{
		class Text : public Image
		{
		public:
			Text();
			Text(std::string);
			~Text();

			void Print(Screen& screen) const;

		private:
			std::string text;
		};
	}
}

#endif // _TEXT_
