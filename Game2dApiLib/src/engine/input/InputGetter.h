#ifndef _INPUT_GETTER_
#define _INPUT_GETTER_

#include "util/Unique.h"
#include "Input.h"

namespace engine
{
	namespace input
	{
		enum class InputGetMode { POOL_INPUT, WAIT_INPUT };

		class InputGetter : public util::Unique<InputGetter>
		{
		public:
			explicit InputGetter(Input& i, InputGetMode newMode = InputGetMode::POOL_INPUT);
			virtual ~InputGetter();

			void GetInput(size_t timeOut_ms);
			inline const Input& Input() const;
		
			inline void ChangeMode(InputGetMode newMode);

		private:
			virtual void PoolInput() = 0;
			virtual void WaitInput(size_t timeOut_ms) = 0;

			input::Input& input;
			InputGetMode mode;

			InputGetter(const InputGetter&) = delete;
			InputGetter& operator=(const InputGetter&) = delete;
		};
	}
}

#endif // _INPUT_GETTER_