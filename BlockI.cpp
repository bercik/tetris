#include "BlockI.h"

std::vector<Point> BlockI::getRelativePoints()
{
	std::vector<Point> points;

	points.push_back(Point(-1, 0));
	points.push_back(Point(0, 0));
	points.push_back(Point(1, 0));
	points.push_back(Point(2, 0));

	return points;
}

sf::Color BlockI::getColor()
{
	return sf::Color::Cyan;
}
