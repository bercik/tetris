#pragma once

#include "Block.h"

class BlockS : public Block
{
public:
	std::vector<Point> getRelativePoints();
	sf::Color getColor();
};
