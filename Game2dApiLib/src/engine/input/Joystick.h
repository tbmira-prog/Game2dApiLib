#ifndef _JOYSTICK_
#define _JOYSTICK_

#include "util/Unique.h"
#include "Input.h"

namespace engine
{
	namespace input
	{
		enum class InputGetMode { POOL_INPUT, WAIT_INPUT };

		class Joystick : public util::Unique<Joystick>
		{
		public:
			explicit Joystick(Input& i, InputGetMode newMode = InputGetMode::POOL_INPUT);
			virtual ~Joystick();

			void GetInput(size_t timeOut_ms);
			inline const Input& Input() const;
		
			inline void ChangeMode(InputGetMode newMode);

		private:
			virtual void PoolInput() = 0;
			virtual void WaitInput(size_t timeOut_ms) = 0;

			input::Input& input;
			InputGetMode mode;

			Joystick(const Joystick&) = delete;
			Joystick& operator=(const Joystick&) = delete;
		};
	}
}

#endif // _JOYSTICK_