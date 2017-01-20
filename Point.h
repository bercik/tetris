#pragma once

class Point
{
public:
	Point() {}
	Point(int x, int y) : x(x), y(y) {}

	Point operator +(Point o) {
		return Point(x + o.x, y + o.y);
	}

	int x, y;
};
