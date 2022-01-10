#ifndef _IMAGE_
#define _IMAGE_

#include "Screen.h"

namespace graph
{
	class Image
	{
	public:
		Image() {};
		virtual ~Image() {};

		Image(const Image&) = default;
		Image& operator=(const Image&) = default;

		virtual void Print(Screen& screen) const = 0;
	};
}

#endif // _IMAGE_