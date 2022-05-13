#ifndef _NULL_IMAGE_
#define _NULL_IMAGE_

#include "util/Unique.h"
#include "Image.h"

namespace engine
{
	namespace graph
	{
		class NullImage : public Image, public util::Unique<NullImage>
		{
		public:
			NullImage() : Image(), Unique<NullImage>() {}
			~NullImage() {}

			void Print(Screen&) const override {}
		};

		NullImage invisible; // HACK Resolver Link Warning
	}
}

#endif // _NULL_IMAGE_