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

		double GetTime(const TimeUnit& unit = TimeUnit::mS) const;

	private:
		std::chrono::time_point<std::chrono::system_clock> startTime, pauseTime, endTime;
		std::chrono::duration<double> runningTime, pausedTime;

		bool running, paused, stoped;
	};
}

#endif // _TIMER_