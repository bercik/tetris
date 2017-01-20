#include "Menu.h"

const unsigned int Menu::numMenuPositions = 3;
const std::string Menu::positions[numMenuPositions] = {"New Game", "High Scores", "Exit"};

Menu::Menu(State *state, Tetris *tetris)
{
	this->tetris = tetris;
	this->state = state;
	this->selectedElement = 0;
}

std::vector<std::string> Menu::getTexts()
{
	std::vector<std::string> result;

	for (unsigned int i = 0; i < numMenuPositions; i++) {
		result.push_back(positions[i]);
	}

	return result;
}

void Menu::update(float deltaTime)
{
	keyboard.update(deltaTime);

	if (keyboard.escape->isDown()) {
		state->currentState = State::MainMenu;
	}

	if (keyboard.down->isDown()) {
		if (selectedElement < numMenuPositions - 1) {
			selectedElement++;
		}
	}

	if (keyboard.up->isDown()) {
		if (selectedElement > 0) {
			selectedElement--;
		}
	}

	if (keyboard.enter->isDown()) {
		switch (selectedElement) {
			case 0:
				state->currentState = State::Game;
				tetris->reset();
				break;
			case 1:
				state->currentState = State::HighScores;
				break;
			case 2:
				exit(0);
				break;
		}
	}
}
