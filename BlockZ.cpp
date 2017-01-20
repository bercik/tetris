#include "BlockZ.h"

std::vector<Point> BlockZ::getRelativePoints()
{
	std::vector<Point> points;

	points.push_back(Point(-1, 0));
	points.push_back(Point(0, 0));
	points.push_back(Point(0, 1));
	points.push_back(Point(1, 1));

	return points;
}

sf::Color BlockZ::getColor()
{
	return sf::Color::Red;
}
