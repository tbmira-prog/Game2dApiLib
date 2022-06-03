#ifndef _JOYSTICK_
#define _JOYSTICK_

#include "util/Unique.h"
#include "Input.h"

namespace engine
{
	namespace input
	{
		enum class InputGetMode { POLL_INPUT, WAIT_INPUT };

		class Joystick : public util::Unique<Joystick> // UNDONE Essa classe não precisa ser única. Como trabalhar com mais de uma ao mesmo tempo?
		{
		public:
			explicit Joystick(engine::input::Input& i, const InputGetMode& newMode, size_t timeOut_ms);
			virtual ~Joystick();

			void GetInput();
			const Input& Input() const;
		
			inline void ChangeMode(InputGetMode newMode);

			void SetTimeOut(size_t newTimeOut) { timeOut_ms = newTimeOut; }
			size_t TimeOut() const { return timeOut_ms; }

		protected:
			input::Input& input;
			InputGetMode mode;
			size_t timeOut_ms;

		private:
			virtual void PollInput() = 0;
			virtual void WaitInput(size_t timeOut_ms) = 0;

			Joystick(const Joystick&) = delete; // UNDONE Mais de um controle em paralelo
			Joystick& operator=(const Joystick&) = delete;
		};
	}
}

#endif // _JOYSTICK_