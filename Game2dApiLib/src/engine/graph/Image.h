#ifndef _IMAGE_
#define _IMAGE_

#include "util/Unique.h"
#include "Screen.h"

namespace engine
{
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

		class Invisible : public Image, public util::Unique<Invisible>
		{
		public:
			Invisible() : Image(), Unique<Invisible>() {}
			~Invisible() {}

			void Print(Screen&) const override {}
		};

		Invisible invisible; // HACK Resolver Link Warning
	}
}

#endif // _IMAGE_