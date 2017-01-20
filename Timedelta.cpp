#include "Timedelta.h"

Timedelta::Timedelta()
{
	currentTime = std::chrono::high_resolution_clock::now();
}

float Timedelta::get()
{
	auto newTime = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float, std::nano> delta = newTime - currentTime;

	currentTime = newTime;

	return delta.count() / (1000 * 1000 * 1000);
}
