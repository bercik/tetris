#include "Board.h"

Board::Board(unsigned int width, unsigned int height) : width(width), height(height)
{
	board = new Field*[width];

	for (unsigned int i = 0; i < width; i++) {
		board[i] = new Field[height];
	}
}

Board::~Board()
{
	for (unsigned int i = 0; i < width; i++) {
		delete[] board[i];
	}

	delete[] board;
}

bool Board::canMoveDown(Block *block)
{
	std::vector<Point> points = block->getPoints();

	for (unsigned int i = 0; i < points.size(); i++) {
		Point point(points[i].x, points[i].y + 1);
		// outside of the board bounds
		if (point.y >= (int)height) {
			return false;
		}
		// already filled
		if (board[point.x][point.y].getFilled()) {
			return false;
		}
	}

	return true;
}

bool Board::canMoveLeft(Block *block)
{
	std::vector<Point> points = block->getPoints();

	for (unsigned int i = 0; i < points.size(); i++) {
		Point point(points[i].x - 1, points[i].y);
		// outside of the board bounds
		if (point.x < 0) {
			return false;
		}
		// already filled
		if (board[point.x][point.y].getFilled()) {
			return false;
		}
	}

	return true;
}

bool Board::canMoveRight(Block *block)
{
	std::vector<Point> points = block->getPoints();

	for (unsigned int i = 0; i < points.size(); i++) {
		Point point(points[i].x + 1, points[i].y);
		// outside of the board bounds
		if (point.x >= (int)width) {
			return false;
		}
		// already filled
		if (board[point.x][point.y].getFilled()) {
			return false;
		}
	}

	return true;
}

bool Board::checkGameOver(Block *block)
{
	std::vector<Point> points = block->getPoints();

	for (unsigned int i = 0; i < points.size(); i++) {
		Point point(points[i].x, points[i].y);
		if (board[point.x][point.y].getFilled()) {
			return true;
		}
	}

	return false;
}

bool Board::canRotate(Block *block)
{
	int rotation = block->getRotation() + 1;

	std::vector<Point> points = block->getPoints(rotation);

	for (unsigned int i = 0; i < points.size(); i++) {
		Point point(points[i].x, points[i].y);
		// outside of the board bounds
		if (point.x < 0) {
			return false;
		}
		if (point.x >= (int)width) {
			return false;
		}
		if (point.y < 0) {
			return false;
		}
		if (point.y >= (int)height) {
			return false;
		}
		// already filled
		if (board[point.x][point.y].getFilled()) {
			return false;
		}
	}

	return true;
}

int Board::checkBoard()
{
	for (int y = height - 1; y >= 0; y--) {
		bool full = true;
		for (int x = 0; x < (int)width; x++) {
			if (!board[x][y].getFilled()) {
				full = false;
			}
		}
		if (full) {
			return y;
		}
	}

	return -1;
}

int Board::moveBoard()
{
	int score = 0;

	while (1) {
		int row = checkBoard();
		if (row < 0) {
			return score;
		}
		score++;
		for (int y = row; y >= 0; y--) {
			for (int x = 0; x < (int)width; x++) {
				if (y > 0) {
					board[x][y].setFilled(board[x][y-1].getFilled());
				} else {
					board[x][y].setFilled(false);
				}
			}
		}
	}
}

void Board::resetBoard()
{
	for (unsigned int x = 0; x < width; x++) {
		for (unsigned int y = 0; y < height; y++) {
			board[x][y].setFilled(false);
		}
	}
}
