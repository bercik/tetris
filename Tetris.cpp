#include "Tetris.h"

Tetris::Tetris(State *state, unsigned int width, unsigned int height)
{
	this->state = state;

	board = new Board(width, height);
	highScore = new HighScore("scores.txt");

	highScore->load();

	reset();
}


Tetris::~Tetris()
{
	delete this->board;
	delete this->highScore;

	if (this->currentBlock) {
		delete this->currentBlock;
	}

	if (this->nextBlock) {
		delete this->nextBlock;
	}
}

void Tetris::reset()
{
	dropCounter = 0;
	moveDownCounter = 0;
	rotateCounter = 0;
	moveRightCounter = 0;
	moveLeftCounter = 0;
	actualScore = 0;

	gameOver = false;

	currentBlock = NULL;
	nextBlock = NULL;

	board->resetBoard();

	spawnBlock();
	spawnBlock();
}

void Tetris::update(float deltaTime)
{
	keyboard.update(deltaTime);

	// exit
	if (keyboard.escape->isDown()) {
		state->currentState = State::MainMenu;
		return;
	}

	if (gameOver) {
		if (keyboard.enter->isDown() && name.size() > 0) {
			highScore->add(actualScore, name);
			state->currentState = State::MainMenu;
		}
		return;
	}

	// left
	if (handleKey(keyboard.left, &moveLeftCounter, moveSidewaysEvery, deltaTime)) {
		if (board->canMoveLeft(currentBlock)) {
			currentBlock->setPosition(currentBlock->getPosition() + Point(-1, 0));
		}
	}

	// right
	if (handleKey(keyboard.right, &moveRightCounter, moveSidewaysEvery, deltaTime)) {
		if (board->canMoveRight(currentBlock)) {
			currentBlock->setPosition(currentBlock->getPosition() + Point(1, 0));
		}
	}

	// rotate
	if (handleKey(keyboard.up, &rotateCounter, rotateEvery, deltaTime)) {
		if (board->canRotate(currentBlock)) {
			currentBlock->setRotation(currentBlock->getRotation() + 1);
		}
	}

	// drop
	bool drop = false;

	if (keyboard.down->isPressed()) {
		moveDownCounter += deltaTime;
	} else {
		moveDownCounter = 0;
	}

	if (moveDownCounter > moveDownEvery) {
		moveDownCounter = 0;
		drop = true;
	}

	dropCounter += deltaTime;

	if (dropCounter > dropEvery) {
		dropCounter = 0;
		drop = true;
	}

	if (drop) {
		if (board->canMoveDown(currentBlock)) {
			Point position = currentBlock->getPosition();
			currentBlock->setPosition(Point(position.x, position.y + 1));
		} else {
			std::vector<Point> points = currentBlock->getPoints();
			for (unsigned int i = 0; i < points.size(); i++) {
				board->board[points[i].x][points[i].y].setFilled(true);
				board->board[points[i].x][points[i].y].setColor(currentBlock->getColor());
			}
			spawnBlock();
		}
	}

	// score
	actualScore += board->moveBoard();

	if (board->checkGameOver(currentBlock)) {
		name = "";
		gameOver = true;
	}
}

bool Tetris::handleKey(Key *key, float *counter, float every, float deltaTime)
{
	bool result = false;

	if (key->isPressed()) {
		if (*counter == 0) {
			result = true;
		}
		*counter += deltaTime;
	} else {
		*counter = 0;
	}

	if (*counter > every) {
		*counter = 0;
		result = true;
	}

	return result;
}

void Tetris::spawnBlock()
{
	if (currentBlock) {
		delete currentBlock;
	}

	currentBlock = nextBlock;

	nextBlock = getRandomBlock();
}

Block *Tetris::getRandomBlock()
{
	Block *block;

	switch (rand() % 7) {
		case 0:
			block = new BlockI;
			break;
		case 1:
			block = new BlockJ;
			break;
		case 2:
			block = new BlockL;
			break;
		case 3:
			block = new BlockO;
			break;
		case 4:
			block = new BlockS;
			break;
		case 5:
			block = new BlockT;
			break;
		case 6:
			block = new BlockZ;
			break;
		default:
			block = new BlockI;
	}

	block->setPosition(Point(board->getWidth() / 2, 0));

	return block;
}

void Tetris::addTextInput(char c)
{
	if (name.size() <= 10) {
		name += c;
	}
}

std::string Tetris::getName()
{
	return name;
}

HighScore *Tetris::getHighScore()
{
	return highScore;
}
