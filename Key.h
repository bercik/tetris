#pragma once

#include <SFML/Window/Keyboard.hpp>

class Key
{
public:
	Key(sf::Keyboard::Key key);

	void update(float deltaTime);
	bool isPressed();
	bool isDown();
	float getCounter();

private:
	sf::Keyboard::Key key;

	bool prev, current;
	float counter;
};
