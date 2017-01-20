#pragma once

class State
{
public:
	State() : currentState(MainMenu) {}

	enum GlobalState { MainMenu, HighScores, Game };
	
	GlobalState currentState;
};
