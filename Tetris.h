#pragma once

#include "Block.h"
#include "BlockI.h"
#include "BlockJ.h"
#include "BlockL.h"
#include "BlockO.h"
#include "BlockS.h"
#include "BlockT.h"
#include "BlockZ.h"
#include "Board.h"
#include "HighScore.h"
#include "Keyboard.h"
#include "Point.h"
#include "State.h"

class WindowedDisplay;

class Tetris
{
	friend class WindowedDisplay;
public:
	Tetris(State *state, unsigned int width, unsigned int height);
	virtual ~Tetris();

	void update(float deltaTime);
	void reset();
	void addTextInput(char c);

	std::string getName();

	HighScore *getHighScore();

private:
	Block *getRandomBlock();

	void spawnBlock();

	bool handleKey(Key *key, float *counter, float every, float deltaTime);

	Block *currentBlock;
	Block *nextBlock;
	Board *board;
	HighScore *highScore;
	Keyboard keyboard;
	State *state;

	float dropCounter;
	static constexpr float dropEvery = 1.0f;

	float moveDownCounter;
	static constexpr float moveDownEvery = 0.05f;

	float rotateCounter;
	static constexpr float rotateEvery = 0.5f;

	float moveRightCounter;
	float moveLeftCounter;
	static constexpr float moveSidewaysEvery = 0.15f;

	int actualScore;
	bool gameOver;
	std::string name;
};
