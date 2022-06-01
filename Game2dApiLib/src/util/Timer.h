#ifndef _TIMER_
#define _TIMER_

#include <ctime>

#include <chrono>

namespace util
{
	enum class TimeUnit {uS, mS, SEC, MIN, HOUR, DAY, MONTH, YEAR};

	class Timer
	{
	public:
		Timer();
		virtual ~Timer();

		void Start();
		void Pause();
		void Stop();

		double GetTime(const TimeUnit& unit = TimeUnit::SEC) const;

	private:
		std::chrono::time_point<std::chrono::system_clock> startTime;
		std::chrono::duration<double> runningTime;

		bool running, paused, stoped;

		double TimeTo(double time, const TimeUnit& unit) const;
	};
}

#endif // _TIMER_