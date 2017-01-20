#pragma once

#include "Block.h"
#include "Field.h"

class Board
{
public:
	Board(unsigned int width, unsigned int height);
	~Board();

	bool checkGameOver(Block *block);
	bool canMoveDown(Block *block);
	bool canMoveLeft(Block *block);
	bool canMoveRight(Block *block);
	bool canRotate(Block *block);

	void resetBoard();
	int checkBoard();
	int moveBoard();

	unsigned int getWidth() { return width; }
	unsigned int getHeight() { return height; }

	Field **board;

private:
	unsigned int width, height;

};
