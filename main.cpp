#include "Menu.h"
#include "Tetris.h"
#include "Timedelta.h"
#include "WindowedDisplay.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	std::srand(std::time(0));

	sf::RenderWindow window;
	Timedelta timeDelta;
	State state;
	Tetris tetris(&state, 10, 20);
	Menu menu(&state, &tetris);

	try {
		WindowedDisplay display(&tetris, &menu, &state, &window);
		while (window.isOpen()) {
			float deltaTime = timeDelta.get();
			switch (state.currentState) {
				case State::MainMenu:
				case State::HighScores:
					menu.update(deltaTime);
					break;
				case State::Game:
					tetris.update(deltaTime);
					break;
				default:
					std::cout << "error" << std::endl;
					exit(1);
			}
			display.draw(&window);
		}
	}

	catch (std::string err)	{
		std::cout << "Error - " << err << std::endl;
	}

	return 0;
}
