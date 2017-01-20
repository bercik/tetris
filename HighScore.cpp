#include "HighScore.h"

HighScore::HighScore(std::string filename)
{
	this->filename = filename;
}

bool HighScore::load()
{
	scores.clear();

	std::ifstream myfile;

	myfile.open(filename);

	if (!myfile.good()) {
		return false;
	}

	std::string name;
	int score;

	while (myfile >> score >> name) {
		scores.push_back(Score(score, name));
	}

	myfile.close();

	sort();

	return true;
}

bool HighScore::save()
{
	std::ofstream myfile;

	myfile.open(filename, std::fstream::trunc);

	if (!myfile.good()) {
		return false;
	}

	for (unsigned int i = 0; i < scores.size(); i++) {
		myfile << scores[i].score << " " << scores[i].name << "\n";
	}

	myfile.close();

	return true;
}

bool HighScore::compare(const Score &a, const Score &b)
{
    return a.score > b.score;
}

void HighScore::sort()
{
	std::sort(scores.begin(), scores.end(), compare);
}

std::vector<Score> HighScore::get()
{
	return scores;
}

void HighScore::add(int score, std::string name)
{
	scores.push_back(Score(score, name));

	sort();

	if (scores.size() > 10) {
		scores.resize(10);
	}

	save();
}
