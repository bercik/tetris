#pragma once

#include "Block.h"

class BlockI : public Block
{
public:
	std::vector<Point> getRelativePoints();
	sf::Color getColor();
};
