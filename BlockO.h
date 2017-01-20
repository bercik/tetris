#pragma once

#include "Block.h"

class BlockO : public Block
{
public:
	std::vector<Point> getRelativePoints();
	sf::Color getColor();
};
