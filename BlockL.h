#pragma once

#include "Block.h"

class BlockL : public Block
{
public:
	std::vector<Point> getRelativePoints();
	sf::Color getColor();
};
