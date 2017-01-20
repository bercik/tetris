#pragma once

#include "Point.h"

#include <vector>
#include <SFML/Graphics.hpp>

class Block
{
public:
	Block() : currentRotation(0) {}
	virtual ~Block() {}
	
	virtual std::vector<Point> getRelativePoints() = 0;
	virtual sf::Color getColor() = 0;

	std::vector<Point> getRelativePoints(int rotation);
	std::vector<Point> getPoints();
	std::vector<Point> getPoints(int rotation);
	bool hasPoint(Point point);

	Point getPosition() { return position; }
	void setPosition(Point position) { this->position = position; }
	int getRotation() { return currentRotation; }
	void setRotation(int rotation) { this->currentRotation = rotation; }

private:
	int currentRotation;
	Point position;
	std::vector<Point> pointsToAbsolute(std::vector<Point> points);
};
