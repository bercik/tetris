#include "WindowedDisplay.h"

WindowedDisplay::WindowedDisplay(Tetris *tetris, Menu *menu, State *state, sf::RenderWindow *window)
{
	this->tetris = tetris;
	this->menu = menu;
	this->state = state;

	if (!font.loadFromFile("PressStart2P-Regular.ttf")) {
	    throw "Failed to load font";
	}

	window->create(sf::VideoMode(blockSize * tetris->board->getWidth(), blockSize * tetris->board->getHeight()), "Tetris");
}

void WindowedDisplay::draw(sf::RenderWindow *window)
{
	sf::Event event;

	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}
		if (event.type == sf::Event::TextEntered) {
			if (event.text.unicode >= 33 && event.text.unicode <= 126) {
				tetris->addTextInput(static_cast<char>(event.text.unicode));
			}
		}
	}

	window->clear();

	switch (state->currentState) {
		case State::MainMenu:
			drawMenu(window);
			break;
		case State::HighScores:
			drawHighScores(window);
			break;
		case State::Game:
			drawGame(window);
			break;
	}

	window->display();
}

void WindowedDisplay::drawGame(sf::RenderWindow *window)
{
	if (tetris->gameOver) {
		std::stringstream sstm;
		sstm << "Game over\n\n";
		sstm << "Score: " << tetris->actualScore << "\n\n";
		sstm << "Write\nyour name:\n";
		sstm << tetris->getName() << "\n\n";
		sstm << "Press\nEnter to save\nor\nEsc to quit\nwithout\nsaving";
		sf::Text text;
		text.setFont(font);
		text.setPosition(0, 0);
		text.setString(sstm.str());
		text.setCharacterSize(15);
		text.setFillColor(sf::Color::White);
		window->draw(text);
		return;
	}

	for (unsigned int y = 0; y < tetris->board->getHeight(); y++) {
		for (unsigned int x = 0; x < tetris->board->getWidth(); x++) {
			if (tetris->currentBlock->hasPoint(Point(x, y)) || tetris->board->board[x][y].getFilled()) {
				sf::RectangleShape rectangle;
				rectangle.setPosition(x * blockSize, y * blockSize);
				rectangle.setSize(sf::Vector2f(blockSize, blockSize));
				if (tetris->currentBlock->hasPoint(Point(x, y))) {
					rectangle.setFillColor(tetris->currentBlock->getColor());
				} else {
					rectangle.setFillColor(tetris->board->board[x][y].getColor());
				}
				window->draw(rectangle);
			}
		}
	}
}

void WindowedDisplay::drawMenu(sf::RenderWindow *window)
{
	sf::Text title;
	title.setFont(font);
	title.setPosition(0, 0);
	title.setCharacterSize(30);
	title.setString("TETRIS");
	title.setFillColor(sf::Color::White);
	window->draw(title);
	
	std::vector<std::string> texts = menu->getTexts();

	for (unsigned int i = 0; i < texts.size(); i++) {
		sf::Text text;
		text.setFont(font);
		text.setCharacterSize(15);
		text.setPosition(0, i * 30 + 45);
		text.setString(menu->getSelectedElement() == i ? "> "+texts[i] : texts[i]);
		text.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1));
		window->draw(text);
	}
}

void WindowedDisplay::drawHighScores(sf::RenderWindow *window)
{
	sf::Text title;
	title.setFont(font);
	title.setPosition(0, 0);
	title.setCharacterSize(15);
	title.setString("Best players:");
	title.setFillColor(sf::Color::White);
	window->draw(title);

	std::vector<Score> scores = tetris->getHighScore()->get();

	for (unsigned int i = 0; i < scores.size(); i++) {
		std::stringstream sstm;
		sstm << std::setfill('.') << std::left << std::setw(9) << scores[i].name;
		sstm << std::right << std::setw(3) << scores[i].score << "\n";
		sf::Text text;
		text.setFont(font);
		text.setPosition(0, i * 30 + 30);
		text.setString(sstm.str());
		text.setCharacterSize(15);
		text.setFillColor(sf::Color::White);
		window->draw(text);
	}
}
