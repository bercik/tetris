#pragma once

#include "Score.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class HighScore
{
public:	
	HighScore(std::string filename);

	std::vector<Score> get();

	bool load();

	void add(int score, std::string name);
	
private:
	bool save();
	static bool compare(const Score&, const Score&);

	void sort();

	std::string filename;
	std::vector<Score> scores;
};
