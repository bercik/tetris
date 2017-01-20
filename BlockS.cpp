#include "BlockS.h"

std::vector<Point> BlockS::getRelativePoints()
{
	std::vector<Point> points;

	points.push_back(Point(-1, 1));
	points.push_back(Point(0, 1));
	points.push_back(Point(0, 0));
	points.push_back(Point(1, 0));

	return points;
}

sf::Color BlockS::getColor()
{
	return sf::Color::Green;
}
