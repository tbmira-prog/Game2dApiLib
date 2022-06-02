#include "Timer.h"
using namespace util;

Timer::Timer() : running(false), paused(false), stoped(true),
				 startTime(), runningTime()
{}

Timer::~Timer() {}

void Timer::Start()
{
	if (stoped)
	{
		startTime = std::chrono::system_clock::now();

		stoped = false;
		running = true;
	}
	else if (paused)
	{
		startTime = std::chrono::system_clock::now();

		paused = false;
		running = true;
	}
}

void Timer::Pause()
{
	if (running)
	{
		runningTime += std::chrono::system_clock::now() - startTime;
		running = false;
		paused = true;
	}
}

void Timer::Stop()
{
	if (running)
	{
		runningTime += std::chrono::system_clock::now() - startTime;
		running = false;
	}
	else if (paused)
	{
		paused = false;
	}
	stoped = true;
}

double Timer::GetTime(const TimeUnit& unit) const
{
	double totalTime = running ?
		(runningTime + std::chrono::system_clock::now() - startTime).count()/10000000 : // HACK Timer retorna unidades diferentes se esta pausado ou parado. Esse tem que retornar segundos
		runningTime.count();

	return TimeTo(totalTime, unit);
}

double Timer::TimeTo(double time, const TimeUnit& unit) const
{
	switch (unit)
	{
	case TimeUnit::uS:
		return time * 1,000,000;
	case TimeUnit::mS:
		return time * 1000;
	case TimeUnit::SEC:
		return time;
	case TimeUnit::MIN:
		return time / 60;
	case TimeUnit::HOUR:
		return time / 60 / 60;
	case TimeUnit::DAY:
		return time / 60 / 60 / 24;
	case TimeUnit::MONTH:
		return time / 60 / 60 / 24 / 30;
	case TimeUnit::YEAR:
		return time / 60 / 60 / 24 / 30 / 365;
	}
}