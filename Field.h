#pragma once

#include <SFML/Graphics.hpp>

class Field
{
public:
	bool getFilled() { return filled; }
	void setFilled(bool filled) { this->filled = filled; }
	sf::Color getColor() { return color; }
	void setColor(sf::Color color) { this->color = color; }

private:
	bool filled;
	sf::Color color;
};
