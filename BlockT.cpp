#include "BlockT.h"

std::vector<Point> BlockT::getRelativePoints()
{
	std::vector<Point> points;

	points.push_back(Point(-1, 0));
	points.push_back(Point(0, 0));
	points.push_back(Point(0, 1));
	points.push_back(Point(1, 0));

	return points;
}

sf::Color BlockT::getColor()
{
	return sf::Color::Magenta;
}
