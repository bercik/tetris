#pragma once

#include "Menu.h"
#include "State.h"
#include "Tetris.h"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

class WindowedDisplay
{
public:
	WindowedDisplay(Tetris *tetris, Menu *menu, State *state, sf::RenderWindow *window);

	void draw(sf::RenderWindow *window);
	void drawGame(sf::RenderWindow *window);
	void drawMenu(sf::RenderWindow *window);
	void drawHighScores(sf::RenderWindow *window);

private:
	Tetris *tetris;
	Menu *menu;
	State *state;
	sf::Font font;

	const int blockSize = 20;
};
