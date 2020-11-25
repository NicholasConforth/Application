#include "pch.h"
#include "Timer.h"

namespace nc
{

	void nc::Timer::Reset()
	{
		m_timePoint = clock::now();
	}

	Timer::clock::rep nc::Timer::ElapsedTicks()
	{
		clock_duration duration = (clock::now() - m_timePoint);

		return duration.count();
	}

	Timer::clock::rep nc::Timer::TicksPerSecond()
	{
		return clock_duration::period::den;
	}

	double nc::Timer::ElapsedSeconds()
	{
		return ElapsedTicks() / static_cast<double>(TicksPerSecond());
	}




	void FrameTimer::Tick()
	{
		m_dt = ElapsedSeconds();
		m_timePoint = clock::now();
	}
	
}
