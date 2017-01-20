#pragma once

#include "Block.h"

class BlockJ : public Block
{
public:
	std::vector<Point> getRelativePoints();
	sf::Color getColor();
};
