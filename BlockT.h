#pragma once

#include "Block.h"

class BlockT : public Block
{
public:
	std::vector<Point> getRelativePoints();
	sf::Color getColor();
};
