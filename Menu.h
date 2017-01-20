#pragma once

#include "Keyboard.h"
#include "State.h"
#include "Tetris.h"

#include <iostream>
#include <string>
#include <vector>

class Menu
{
public:
	Menu(State *state, Tetris *tetris);
	virtual ~Menu() {}

	std::vector<std::string> getTexts();

	void update(float deltaTime);

	unsigned int getSelectedElement() { return selectedElement; }

private:
	Keyboard keyboard;
	State *state;
	Tetris *tetris;
	
	static const unsigned int numMenuPositions;
	static const std::string positions[];

	unsigned int selectedElement;
};
