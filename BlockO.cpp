#include "BlockO.h"

std::vector<Point> BlockO::getRelativePoints()
{
	std::vector<Point> points;

	points.push_back(Point(-1, 0));
	points.push_back(Point(-1, 1));
	points.push_back(Point(0, 0));
	points.push_back(Point(0, 1));

	return points;
}

sf::Color BlockO::getColor()
{
	return sf::Color::Yellow;
}
