#pragma once

#include <string>

class Score
{
public:
	Score() {}
	Score(int score, std::string name) : score(score), name(name) {}

	int score;
	std::string name;
};
