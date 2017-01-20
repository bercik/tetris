#include "Block.h"

std::vector<Point> Block::pointsToAbsolute(std::vector<Point> points)
{
	std::vector<Point> result;

	for (unsigned int i = 0; i < points.size(); i++) {
		result.push_back(Point(points[i].x + position.x, points[i].y + position.y));
	}

	return result;
}

std::vector<Point> Block::getRelativePoints(int rotation)
{
	std::vector<Point> result = getRelativePoints();

	for (int n = 0; n < rotation; n++) {
		for (unsigned int i = 0; i < result.size(); i++) {
			int newX = -result[i].y;
			int newY = result[i].x;
			result[i].x = newX;
			result[i].y = newY;
		}
	}

	return result;
}

std::vector<Point> Block::getPoints()
{
	return pointsToAbsolute(getRelativePoints(currentRotation));
}

std::vector<Point> Block::getPoints(int rotation)
{
	return pointsToAbsolute(getRelativePoints(rotation));
}

bool Block::hasPoint(Point point)
{
	std::vector<Point> points = getPoints();

	for (unsigned int i = 0; i < points.size(); i++) {
		if (points[i].x == point.x && points[i].y == point.y) {
			return true;
		}
	}

	return false;
}
