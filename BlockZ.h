#pragma once

#include "Block.h"

class BlockZ : public Block
{
public:
	std::vector<Point> getRelativePoints();
	sf::Color getColor();
};
