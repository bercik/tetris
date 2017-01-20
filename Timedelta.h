#pragma once

#include <chrono>

class Timedelta
{
public:
	Timedelta();

	float get();

private:
	std::chrono::high_resolution_clock::time_point currentTime;
};
