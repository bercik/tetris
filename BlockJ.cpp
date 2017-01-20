#include "BlockJ.h"

std::vector<Point> BlockJ::getRelativePoints()
{
	std::vector<Point> points;

	points.push_back(Point(-1, 0));
	points.push_back(Point(0, 0));
	points.push_back(Point(1, 0));
	points.push_back(Point(1, 1));

	return points;
}

sf::Color BlockJ::getColor()
{
	return sf::Color::Blue;
}
