#include "Timer.h"
using namespace util;

Timer::Timer() : running(false), paused(false), stoped(true),
				 startTime(), pauseTime(), endTime(),
				 runningTime(), pausedTime()
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

		paused = false;
		running = true;
	}
}

void Timer::Pause()
{
	if (running)
	{
		pauseTime = std::chrono::system_clock::now();
		runningTime = pauseTime - startTime;
		running = false;
		paused = true;
	}
}

void Timer::Stop()
{
	if (running)
	{
		endTime = std::chrono::system_clock::now();
		running = false;
	}
	else if (paused)
	{
		endTime = pauseTime;
		paused = false;
	}
	stoped = true;
}

double Timer::GetTime(const TimeUnit& unit = TimeUnit::mS) const
{
	if (running)
		return;
	else
		return;

}
