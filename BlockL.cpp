#include "BlockL.h"

std::vector<Point> BlockL::getRelativePoints()
{
	std::vector<Point> points;

	points.push_back(Point(-1, 1));
	points.push_back(Point(-1, 0));
	points.push_back(Point(0, 0));
	points.push_back(Point(1, 0));

	return points;
}

sf::Color BlockL::getColor()
{
	return sf::Color(225, 165, 0);
}
